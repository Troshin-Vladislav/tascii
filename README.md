TASCII
======

Program list ascii table

INSTALL:
--------

	$ make

or

	$ g++ tascii.o -o tascii

SYNTAX:
--------

	$ tascii

	$ tascii <first> <end>

first - first code for table ascii
end - end code for table ascii

FORMAT:
--------

[dec]( [hex] ): [char]

	40(28): (
	41(29): )
	42(2A): *
	43(2B): +
	44(2C): ,

EXAMPLES:
---------

see all table ascii:

	$ ./tascii

start from 50 and finished 60 code by table ascii

	$ ./tascii 50 60

