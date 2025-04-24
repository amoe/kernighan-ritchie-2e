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
basically unspecified in K&R, but in ANSI ints are at least 16 bits wide.

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

We observe that raising negative integers to positive integer values results in
the sign flipping back and forth depending on the odd/even status of the
exponent.

They use the word _parameter_ for the value used in the function itself:

```
int power(int x, int y) {
    /* inside here, x and y are termed parameters */
}
```

Whereas in the call `power(2, 3)`, the values 2 and 3 are _arguments_.

They describe the contract of `main` and note that 0 indicates success, while
nonzero indicates an error.

They describe a very old form of C where functions were declared in a different
weird style:

```
power(base, n)
int base, n;
{
    /* function body goes here */
}
```

Apparently this style is still accepted by compilers, called K&R style.

## Ex1-15

Done.

## 1.8 Arguments -- call by value

All arguments are passed by value.  C functions can't directly alter a variable.

You can work around this using pointers which are covered in chapter 5.

Arrays are treated differently, though.  Arrays are not copied and they are
passed as an address.  Hence, arrays function as if they were call-by-reference.

This is actually very similar to the way that lists behave in Python.

## 1.9 Character Arrays

I wrote the longest-line program blind, and it sort of works, but we don't know
about null-terminated strings in C yet.

Functions can take array-typed arguments in ANSI C:


     int getline(char buffer[]) { ... }

Here, `buffer` still ends up being passed as a pointer despite the typing.

They write the `copy` function (`strcpy`) without a destination parameter which
means it's null terminated.  Also they write the prototype backwards
(destinaton, source).  Which does actually seem to be the prototype for the
standard `strcpy` function.

This is an interesting factoring which does allow us to keep the main algorithm
fairly clean, while using explicit copies when necessary.

## 1.10 External Variables and Scope

Points:

Local variables are local (they only exist in the scope of the declaring
function). Local variables are also local to a function specifically (rather
than some other area of code).

The term 'automatic variables' is used.  This means that they get set up when
the function is called, and they automatically disappear (because they are
allocated on the stack).

K&R point out that variables don't retain their value across calls.  No one
would now expect this to be the case.  But additionally they are also
undefined at initialization and probably contain some arbitrary value (which is
not the case in most post-C languages).  Low level languages enforce
initialization through various means, usually by explicitly requiring it as a
compile time check.

There's such a thing as *external* variables.  This is essentially a global
variable that remains in existence permanently.  However they are using this
term _without_ invoking the explicit C keyword `extern`.  TBD.

External variables are declared at the global level and then declared `extern`
in each function.  Extern is mainly used when splitting programs across multiple
files.  Because you can declare a variable multiple times but you can only
define it once.

They note that in ANSI C you should not declare no-args functions thus:

    int getline();

instead:

    int getline(void);

Otherwise the compiler turns off all args checks!  This is quite insane, I had
no idea about this.  You can use -Wstrict-prototypes to enforce this.

On definition vs declaration, K&R say this:

> 'Definition' refers to the place where the variable is created or assigned
> storage; 'declaration' refers to places where the nature of the variable is
> stated but no storage is allocated.

K&R warn against the overuse of extern, which obviously suffers from all the
issues that FP attempts to mitigate.  K&R say we now know enough C to be pretty
useful.

Ex1-20 -- K&R seem to use "symbolic parameter" to mean "preprocessor constant",
or a #define.  Clearly the answer is that the tab stop size should be a
'symbolic parameter' in this sense.

Ex1-21 -- This is fairly straightforward state-machine style program that
accumulates tabs and then optimizes them with quotient/remainder

> When either a tab or a single blank would suffice to reach a tab stop, which
> should be given preference?

This is actually way more complicated because it's not just as simple as saying:
"a tab produces 8 spaces".  Rather, a tab jumps the notional cursor to the next
tab stop.  I rewrote 1-20 to detab using the modulus operator.

# Chapter 2: Types, Operators and Expressions

ANSI C added some things with respect to the types available in C:

* Signed and unsigned forms of all integers along with notations for their
  values
* Float operations possible with the `float` type and also a distinct `long
  double` type.
* Concatenation of string contants at compile time
* Adding enumerations.
* Adding the `const` qualifier for declarations.
* New rules for coercion during arithmetic to support the above changes.

## 2.1 Variable Names

It's normal in C to use lower case for variable names and uppercase for
constants.

For a regular variable (or 'internal name'), variables are unique to 31.
For internal names (local variables) I think: 31 chars are significant; this is
a conservative estimate.

For external names, they should be case insensitive and unique to 6 characters.
This is K&R but this is really crusty.  You can use 31 char external names in
ANSI C so don't worry about this.

## 2.2 Data Types and Sizes

C types (in the context of K&R/ANSI period) are:

* char -- 1 byte (or a character if-and-only-if the local charset fits into 8 bits).
* int -- arbitrarily sized integer, under ANSI must be at least 16 bits wide
* long -- commonly expected to be at least 32 bits
* float -- at least 32 bit value
* double -- commonly expected to be 64 bit

Integer types can be modified using 'short' and 'long'.

K&R write:

> int will normally be the natural size for a particular machine

The notion that the int type 'represents the native int size' seems to be wrong,
as I am on x86_64 Mac, and get a 32 bit integer.  There was a decision made
during the development of C to keep the size at 32 bits for C compatibility.
Toolchains make a decision to keep the size of 'int' as 32, presumably because
there's just too much 32 bit code.

It's undefined whether a plain 'char' is signed or unsigned (!!!)
This is kind of mad, so you should always default to unsigned char.
Basically a plain char is always a code smell.

You can specify a 'long double', unclear how large this is.  On my platform, a
long double is twice the size of a double (128bit or 16 bytes, quite a huge
value).

C99 provides uint8_t which can be useful, some people define byte to unsigned
char.

<limits.h> provides these sizes which are also obtainable from sizeof()
statement.

Ex2-1 notes -- This is rather hard and involved learning some new stuff that
isn't in the book.
I don't think that this exercise is doable without knowing the representation of
the floats, to at least some level, or at least knowing some
implementation-specific behaviours of arithmetic.
I made a blog post about this problem ("Floating Point Representation").

## 2.3 Constants

Long constants are written with an `L` suffix: `123456789L`.

You can explicitly denote an unsigned constant with `100U` for instant, this
will be of type `unsigned int`.

There are no short constant as short isn't generally as useful, because mostly
`int` corresponds to the word size and therefore is the most efficient type.

By default any floating point constant is `double`.  Double is therefore the
default type.  You can suffix with `F` to get an explicitly float-valued
constant.  Octal and hexadecimal constants are supported.

You can escape a question mark, for some reason to do with trigraphs.

`strlen` exists as part of the C89 standard library.

These two declarations:

    char *foo = "MYSTRING";

and

    char foo[] = "MYSTRING";

Are compiled in totally different ways.  The pointer notation is compiled into a
read only data segment.  The `foo[]` notation has stuff copied onto the stack at
runtime so might even be slower, and isn't read only.  However, `const char[]
foo` is actually better all round.


A discussion of enums.

    enum months {
        JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
    };

Note we specify the starting value and the rest of the values are all generated
by incrementing the counter.  The value is of type int.  Enums here are seen as
an alternative to #define.


Note that `months` also becomes a type here, and you can assign to it, but
values aren't type checked at compile time at all.  So this is legal:

    enum months my_month = 22;   /* DOH, won't even generate a warning */

A bug has been raised for this with not much result:
https://gcc.gnu.org/bugzilla/show_bug.cgi?id=67314


## 2.4 Declarations

K&R write (p40):

> If the variable in question is not automatic, the initialization is done once
> only, conceptually before the program starts executing, and the initializer
> must be a constant expression.

Remember that 'automatic variable' is used here as an antonym for static.  So
any extern or static variables will have this initialization behaviour.  This is
to do with 'lifetimes' a later term.  Note that automatic variables are in-fact
initialized every etnry into the block.

> External and static variables are initialized to zero by default.  Automatic
> variables have undefined values.

This is a fairly important quirk, and it's because non-automatic variables live
in the BSS section of the binary, this is a portion of the object file that
contains variables that are essentially automatically zeroed, so it's cost-free
to initialize them.

Discussion of the const qualifier:

* For a scalar, the value will not be changed.
* For an array, the elements will not be altered.

`const char[] foo` is the preferred notation for constant messages and such, as
it has the most compile-time guarantees and restrictive behaviour.

When accepting an array parameter, this indicates the function does not change
the array.  `const` does not specifically guarantee that compilers will flag the
result as an error frustratingly.


## 2.5 Arithmetic Operators

Modulus is only defined on integers.  The modulus operation does exist for
floating point numbers, but C only defines it for integers.
  
Truncation for positive integers behaves predictable e.g. 5 / 2 is guaranteed to
be 2, but -5 / 2 is implementation defined.  It could be either towards zero in
which case the result is -2, or towards negative infinity in which case the
result is -3.  However C99 standardises this to be towards zero, so the result
in C99 is always -2.
  
