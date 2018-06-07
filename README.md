TASCII
======

Program list ascii table

INSTALL:
--------

	$ make

or

	$ g++ tascii.cpp -o tascii

SYNTAX:
--------

	$ tascii [options]

OPTIONS:
--------


**--start <int>, -s <int>:** 

start code char

**--finish <int>, -f <int>:** 

finish code char

**--bound <int>, -b <int>:** 

specified count char outputing on console (default = 10)

**--inline, -i:** 

inline mode - all char will print in line, and bound specified parameters --bound

**--hex, -h:** 

view char code in heximal digits

**--dec, -d:** 

view char code in decimal digits

**--help, -h:** 

print help page and exit


FORMAT:
--------

ORIGIN:

dec(hex): char

	40(28): (
	41(29): )
	42(2A): *
	43(2B): +
	44(2C): ,

INLINE:

\[hex\]\(dec\)'char'

	[3C]'<' [3D]'=' [3E]'>' [3F]'?' [40]'@' 
	[41]'A' [42]'B' [43]'C' [44]'D' [45]'E'


EXAMPLES:
---------

show all table ascii:

	$ ./tascii

show ascii symbols start of 60 and finished 120 

	$ ./tascii --start 60 --finish 120

show table start of 60 and finished 70 char code, view heximal digits with bound 5 times

	$ ./tascii --inline -s 60 -f 70 --hex --bound 5
