def ex_1_21():
    return [
        (b'foobar\n', b'foobar\n'),
        (b'foo     \n', b'foo\t\n'),
        (b'foobar00foo     \n', b'foobar00foo\t\n'),
        (b'foobar  \n', b'foobar\t\n'),
        (b'foo bar baz quux\n', b'foo bar\tbaz quux\n'),
        (b'foobar0 \n', b'foobar0\t\n'),
        (b'foobar00foobar0 \n', b'foobar00foobar0\t\n'),
        (b'foobar00 oobar0 \n', b'foobar00 oobar0\t\n'),
        (
            b'abcdefghabcd                        efghabcdefgh\n',
            b'abcdefghabcd\t\t\t    efghabcdefgh\n'
        ),
        (b'\n', b'\n'),
    ]


def ex_1_22():
    return [
        (b'foobar\n', b'foobar\n'),
    ]
