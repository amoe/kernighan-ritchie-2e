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

## 1.3 The For Statement

We replace the 'while' loop with a more compact equivalent for loop.

> In any context where it is permissible to use the value of a variable of some
> type, you can use a more complicated expression of that type.

This seems to be another way of talking about the property of referential
transparency, or the action designated by beta reduction.

    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));

Here the %f from the format string takes the complex float-valued expression.

This property is now standard in programming language but was probably novel at
the time.

Re the choice of 'while' vs 'for':

> The `for` is usually appropriate for loops in which the initialization and
> increment are single statements and logically related, since it is more
> compact than `while` and it keeps the loop control statements together in one
> place.

## 1.4 Symbolic Constants

They introduce preprocessor macros.  They call them "Symbolic Constants".

They recommend these as a way for defining all constants.

Interestingly they use the horizontal alignment style which I now hate.

## 1.5 Character Input and Output

A family of text-based programs work on line-oriented data.

C provides `getchar` and `putchar` for input and output of single characters
respectively.  `getchar` returns a char value.  For now most input will come
from the keyboard.  [Will getchar use line buffering? -DB]

`putchar` and `printf` can be interleaved and they don't buffer, theoretically
speaking.


Using this you can write the `cat` program.  The example they give uses the
'loop and a half' pattern.

You designate the EOF check as

```
while (c != EOF) { ... }
```

`cat` is pleasantly simple.

Instead of using `char` they use `int`.
`char` is of an unknown width.  They seem to make an assumption that `int` is
wider than `char`, which seems like it may not be the case?
I'm pretty sure after a bit of research that this is an extant portability
issue, albeit purely theoretical, so this particular notion is not strictly ok.

Re EOF:

> The specific numeric value doesn't matter as long as it is not the same as any
> `char` value.

The second version of the program combines the assignment with the comparison in
the while loop.  This is somewhat equivalent to Python's 'walrus operator'.

`!=` has higher precedence (binds tighter) than `=` by default which means that:

    c = getchar() != EOF

Would be parsed as:

    c = (getchar() != EOF)

By default.  Which is probably what one would expect.  So the parens are
necessary to enforce:

    (c = getchar()) != EOF

## Ex 1.6

> Verify that the expression `getchar() != EOF` is 0 or 1.

We empirically check by assigning and printing the value, we can see that the
expression is 1 until the end of the file, when it becomes 0.

## Ex 1.7

> Write a program to print the value of EOF.

It prints:

> The value of EOF is: -1

So we can assume that because `int` is signed, and `char` can never be <0, that
EOF constitutes an out-of-band signal in the manner desired.

## 1.5.2 Character Counting

A long is at least 32 bits.

K&R introduce a character counting program (which may be characterized by a
large value for a big file).

If you use a double to track the number you might be able to get even larger
values.

REVIEW: What does this do:

> printf("%.0f\n", nc);

Answer: Suppresses the printing of the decimal point of a `double` value.
They suggest using a double but this doesn't sound wise because a double becomes
inaccurate at higher values.

An isolated semicolon is called a "null statement".

A value between two single quotes is called a character constant: 'A' etc.  It
is just a small integer.

They note that

> "\n" is a string constant that happens to contain only one character

But arguably this is not actually true, it contains two characters -- counting
the null terminator.

## 1-10

> Write a program to copy its input to its output, replacing each tab by \t,
> each backspace by \b, and each backslash by \\.  This makes tabs and
> backspaces visible in an unambiguous way.

## 1.5.4 Word Counting

This introduces the else clause, including else if.  It also recommends defining
symbolic constants to designate both cases of a boolean variable.  It also
introduces the || and && operators, greatly simplifying things, and the notation
for assigning multiple variables at once.

## Exercise 1-11

Need to test all kinds of boundary conditions.  For instance, need to define
what the correct behaviour is for strings like " \n \t " etc.

## 1-6

k&r implement the 'isdigit' test like so:

    if (c > '0' && c <= '9') {
    }

So we assume here we're dealing with ASCII.

Nothing too remarkable here:
* No pointers yet, everything is initialized with loops.
* Subscripts `a[i]` can be dynamic, as you would hope.

## Ex 1-13, 1-14

All implemented.  Nothing too challenging here, except the lack of functions
does show as making things more difficult.

## 1.7 Functions

It's possible to define and call a function only once (and K&R do not censure
this usage).  It's not just to remove duplication, rather it's for clarification.

We define a power function.
