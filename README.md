# Usage
truetable [ -e expression | -f FILE ]
truetable -?|-h|--help
truetable -v|--version

# Description
This is a program which prints true table according to the given expression.

`!`: not
`&`: and
`|`: or
`>`: implication
`#`: double implication
`A-Z`: element

# Options
-h|--help
    print help message.

-v|--version
    print version

-e expression
    print true table accoriding each expresion.

-f FILE
    read FILE, each line is an expression, then print all true tables.

**NOTE**:
if no option is given, program will read expression from standard input.

# NOTE
This is a refactoring with [better string library](http://bstring.sf.net/).
dbg.h is from [learn c the hard way](http://c.learncodethehardway.org/book) [Exercise 20](http://c.learncodethehardway.org/book/learn-c-the-hard-waych21.html#x26-10600021).

# LICENSE
## MIT LICENSE

Copyright (C) 2012 Liqiang Lee

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"), to
deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
