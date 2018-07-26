/-
Copyright (c) 2018 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Author: Sebastian Ullrich

Reader for the Lean language
-/
prelude
import init.lean.parser.parsec init.lean.parser.syntax init.lean.parser.macro
import init.lean.parser.identifier

/-- A small wrapper of `reader_t` that simplifies introducing and invoking
    recursion points in a computation. -/
-- TODO(Sebastian): move?
def rec_t (r : Type) (m : Type → Type) (α : Type) :=
reader_t (m r) m α

namespace rec_t
variables {m : Type → Type} {r α : Type} [monad m]
local attribute [reducible] rec_t

/-- Continue at the recursion point stored at `with_recurse`. -/
def recurse : rec_t r m r :=
⟨λ rec, rec⟩

variables (base : m r) (rec : rec_t r m r)
private def with_recurse_aux : nat → m r
| 0     := base
| (n+1) := rec.run (with_recurse_aux n)

/-- Execute `rec`, re-executing it whenever `recurse` is called.
    After `max_rec` recursion steps, `base` is executed instead. -/
def with_recurse (max_rec := 1000) : rec_t r m r :=
⟨λ _, rec.run (with_recurse_aux base rec max_rec)⟩

instance : monad (rec_t r m) := infer_instance
instance [alternative m] : alternative (rec_t r m) := infer_instance
instance : has_monad_lift m (rec_t r m) := infer_instance
instance (ε) [monad_except ε m] : monad_except ε (rec_t r m) := infer_instance
instance [alternative m] [lean.parser.monad_parsec m] : lean.parser.monad_parsec (rec_t r m) :=
infer_instance
end rec_t

namespace lean
-- TODO: enhance massively
def message := string

namespace parser

structure token_config :=
(«prefix» : string)
-- reading a token should not need any state
/- An optional parser that is activated after matching `prefix`.
   It should return a syntax tree with a "hole" for the
   `source_info` surrounding the token, which will be supplied
   by the `token` reader. -/
(token_reader : option (parsec (source_info → syntax)) := none)

structure reader_state :=
(tokens : list token_config)
(fatal : bool)
(errors : list lean.message)

def reader_state.empty : reader_state :=
⟨[], ff, []⟩

structure reader_config := mk

@[irreducible] def read_m := rec_t syntax $ reader_t reader_config $ state_t reader_state $ parsec

structure reader :=
(read : read_m syntax)
(tokens : list token_config := [])

namespace read_m
local attribute [reducible] read_m
instance : monad read_m := infer_instance
instance : alternative read_m := infer_instance
instance : monad_reader reader_config read_m := infer_instance
instance : monad_state reader_state read_m := infer_instance
instance : monad_parsec read_m := infer_instance
instance : monad_except parsec.message read_m := infer_instance

--TODO(Sebastian): expose `reader_state.errors`
protected def run {α : Type} (cfg : reader_config) (st : reader_state) (s : string) (r : read_m α) :
  except parsec.message α :=
prod.fst <$> (((r.run (monad_parsec.error "no recursive parser at top level")).run cfg).run st).parse_with_eoi s
end read_m

namespace reader
open monad_parsec

protected def parse (cfg : reader_config) (s : string) (r : reader) :
  except parsec.message syntax :=
-- the only hardcoded tokens, because they are never directly mentioned by a `reader`
let tokens : list token_config := [⟨"/-", none⟩, ⟨"--", none⟩] in
r.read.run cfg ⟨r.tokens ++ tokens, ff, []⟩ s

namespace combinators
def node' (m : name) (rs : list reader) : reader :=
{ read := do {
    args ← rs.mmap reader.read,
    pure $ syntax.node ⟨m, args⟩
  },
  tokens := rs.bind reader.tokens }

def seq := node' name.anonymous
def node (m : macro) := node' m.name

def many (r : reader) : reader :=
{ r with read := do
    args ← many r.read,
    pure $ syntax.node ⟨name.anonymous, args⟩ }

def many1 (r : reader) : reader :=
{ r with read := do
    args ← many1 r.read,
    pure $ syntax.node ⟨name.anonymous, args⟩ }

def optional (r : reader) : reader :=
{ r with read := do
    r ← optional r.read,
    pure $ match r with
    | some r := syntax.node ⟨name.anonymous, [r]⟩
    | none   := syntax.node ⟨name.anonymous, []⟩ }

/-- Parse a list `[p1, ..., pn]` of readers as `p1 <|> ... <|> pn`.
    Note that there is NO explicit encoding of which reader was chosen;
    readers should instead produce distinct node names for disambiguation. -/
def any_of (rs : list reader) : reader :=
{ read   := (match rs with
    | [] := failure
    | (r::rs) := (rs.map reader.read).foldl (<|>) r.read),
  tokens := (rs.map reader.tokens).join }

def try (r : reader) : reader :=
{ r with read := try r.read }

def label (r : reader) (l : string) : reader :=
{ r with read := label r.read l }

infixr <?> := label

local attribute [reducible] read_m
def recurse : reader :=
{ read   := rec_t.recurse,
  tokens := [] } -- recursive use should not contribute any new tokens

def with_recurse (r : reader) : reader :=
{ r with read := rec_t.with_recurse (error "recursion limit") r.read }
end combinators
end reader
end parser
end lean