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

        # The happy path.
        (b'foo bar baz\n', b'foo bar\nbaz\n'),

        # We should only output a trailing newline if the trailing newline was
        # already present in the input.
        (b'foo bar baz', b'foo bar\nbaz'),

        # 'Very long lines' means presumably exceeding a hardcoded buffer size.
        # Our buffer size is only going to be 128 bytes.
        # Can't we just support unlimited length?
        # Something like:
#        (b' '.join([b'foo bar baz'] * 12), 


        # Something intelligent is not clear in this case but it makes sense that
        # we can only really break the line at the Nth column as we don't have
        # any info about the structure of the text.
        (b'foobarbaz\n', b'foobarba\nz\n')
    ]


def ex_1_24():
    return [
        (b'()\n', b'OK\n'),
        (b'(())\n', b'OK\n'),
        (b'(()\n', b'FAIL\n'),
        (b"('(')\n", b'OK\n')
    ]
