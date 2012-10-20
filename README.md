# Usage
truetable [ -e expression | -f FILE ]
truetable -?|-h|--help
truetable -v|--version

# Description
This is a program which prints true table according to the given expression.

* `!`: not
* `^`: conjunction
* `v`: disjunction
* `>`: implication
* `#`: equivalence
* `A-Z`: element


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
* This is a refactoring with [better string library](http://bstring.sf.net/).
* dbg.h is from [learn c the hard way](http://c.learncodethehardway.org/book) [Exercise 20](http://c.learncodethehardway.org/book/learn-c-the-hard-waych21.html#x26-10600021).
