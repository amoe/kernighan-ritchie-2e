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

## Ex1-1

Done

## Ex1-2

Done, and the escaped character just got swallowed.   I assume because it was a
\a which triggers a bell (but it's probably suppressed by my terminal).


## 1.2 Variables and Arithmetic Expressions

All variables must be declared before they are used.

In this book, they expect ints to be 16-bit  or 32-bit, but the range of ints is
basically unspecified.

floats are expected to be 32-bit.   This still applies now because of IEEE 754.
They define the range of a float as 10^-38 to 10^38 and six significant digits.

There are some other types included in ANSI:

* char
* short
* long
* double

You can't rely on the size of these types.  `float` is the most reliable, but
still not technically guaranteed.  C99 has int8_t for if you really want to
guarantee an 8-bit char.

K&R are using a four space tab stop.

Re:

    celsius = 5 * (fahr - 32) / 9

>  The reason for multiplying by 5 and then dividing by 9 instead of just
>  multiplying by 5/9 is that in C, as in many other languages, integer division
>  _truncates_: any fractional part is discarded.

So basically this means that you want to do any integer divisions at the last
possible point to avoid losing information.  Luckily the fractional part (and
rounding behaviour) isn't important for this particular case.

`printf` is not part of the C language, rather it's part of the library, but it
is defined by the standard.  They recommend `scanf` for reading numbers, but we
know that this advice is not current nowadays.

They right-justify number for easier comprehension.  Using syntax like `%3d` to
`printf` will automatically right-justify the relevant number.  I did not know
this.

`%6.1f` specifies right justification, to a width of 6 characters, and keeping 1
fractional decimal point during display.

If the width is omitted then no right-justify will occur.

## Ex1-4

If

y = (5/9) * (x - 32)

Solve for x:


(9/5)y = x - 32

(9/5)y + 32 = x

x = ((9/5)*y) + 32

