Git Commit Convention
=====================

We are using the following convention for writing git-commit messages.
It is based on the one from AngularJS project([doc][angularjs-doc],
[commits][angularjs-git]).

[angularjs-git]: https://github.com/angular/angular.js/commits/master
[angularjs-doc]: https://docs.google.com/document/d/1QrDFcIiPjSLDn3EL15IJygNPiHORgU1_OOAqWjiDU5Y/edit#

Format of the commit message
----------------------------

    <type>(<scope>): <subject>
    <NEWLINE>
    <body>
    <NEWLINE>
    <footer>

``<type>`` is:

 - feat (feature)
 - fix (bug fix)
 - doc (documentation)
 - style (formatting, missing semicolons, ...)
 - refactor
 - test (when adding missing tests)
 - chore (maintain, ex: travis-ci)
 - perf (performance improvement, optimization, ...)

``<scope>`` is a name of module or a directory which contains changed modules. For instance,
it could be

 - kernel/expr
 - kernel
 - library/rewrite

``<subject>`` has the following constraints:

 - use imperative, present tense: "change" not "changed" nor "changes"
 - do not capitalize the first letter
 - no dot(.) at the end

``<body>`` has the following constraints:

 - just as in ``<subject>``, use imperative, present tense
 - includes motivation for the change and contrasts with previous
   behavior

``<footer>`` is optional and may contain two items:

 - Breaking changes: All breaking changes have to be mentioned in
   footer with the description of the change, justification and
   migration notes
 - Referencing issues: Closed bugs should be listed on a separate line
   in the footer prefixed with "Closes" keyword like this:

    Closes #123, #456

Examples
--------

fix(kernel): add declarations for operator<<(std::ostream&, expr const&) and operator<<(std::ostream&, context const&) in the kernel

The actual implementation of these two operators is outside of the
kernel. They are implemented in the file 'library/printer.cpp'. We
declare them in the kernel to prevent the following problem. Suppose
there is a file 'foo.cpp' that does not include 'library/printer.h',
but contains

    expr a;
    ...
    std::cout << a << "\n";
    ...

The compiler does not generate an error message. It silently uses the
operator bool() to coerce the expression into a Boolean. This produces
counter-intuitive behavior, and may confuse developers.

"Prepare commit message" git hook
=================================

Execute the following in the project root directory
to activate a little script that tries to synthesize
the first part of the commit message:

```bash
ln -s ../../script/prepare-commit-msg .git/hooks
```

Currently, it will only activate if just a single file has changed.
