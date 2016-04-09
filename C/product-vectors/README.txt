SAMPLE VECTORS FOR PRODUCT CIPHER LAB
-------------------------------------

INTRODUCTION
------------

This archive contains sample input, keys, output and TWO testing
scripts.  'test'.sh' performs encoding/decoding for each input and
key using a variety of numbers of rounds. 

The scripts test.sh and padtest.sh use the following directories:

Contents:
	input/		-- sample inputs
	correct/	-- correctly encoded inputs
	ENCODED/	-- YOUR encoder's output files are put here
	DECODED/	-- YOUR decoder's output files are put here
	log/		-- program stdin and stderr from your encoder/decoder
	test.sh		-- runs full tests
	checksums 	-- contains checksums for test data integrity checking

INSTRUCTIONS FOR TEST.SH
------------------------

Copy your encoder.c and decoder.c files into this directory. Run
'./test.sh'. This will compile encoder.c and decoder.c and run all
combinations of inputs and keys with a variety of numbers of rounds. 

Encoded data is written into ENCODED/ and compared against the correct
version in correct/. Decoded data is written into DECODED/ and
compared against the original input in input/.  Standard output and
error for your programs are written to files in log/.

Successes and failures are counted and results are printed at the end.

OPTIONS FOR TEST.SH
-------------------

Run ./test.sh -h for a list of all options. Some of them are very
helpful!

QUESTIONS / PROBLEMS?
---------------------

Contact your instructor or TA immediately!
