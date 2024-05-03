# K&R 2e

Their first hello world example gives a warning in clang.  It seems that the
correct set of commands to use is just `-std=c89`.

The basic unit of code in C is called a _function_ which contains _statements_.
It's good to know these language-specific terms in order to communicate clearly.

Every program begins executing at `main`: "every program must have a `main`
somewhere".

A function that expects no arguments is indicated using `()`.

The statements of a function are enclosed in braces.

Multiline strings do not seem valid in C, e.g. this does not work:

    printf("hello, world
    ");

Which it does in e.g. Perl.

You may use different calls to the `printf` function to gradually build up
output as you receive it.  This is an odd technique that likely would not be
used now.
