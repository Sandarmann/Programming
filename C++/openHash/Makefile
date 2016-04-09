#################################################################
#
#  Makefile for open addressing hash program, CS 4521, Fall 2009
#
#  Files:
#  cmdint2.cpp      The main program
#
#  openhash.h       The header file for the Open Hash class
#  openhash.cpp     The implemention file for the Open Hash class
#
#  cmdint2          The executable program
#
#  Created by:      D. Dunham  November 2, 2009
#
##################################################################

CC = g++ 
DEBUG = -O

CFLAGS = $(DEBUG) -c

TARGETS = cmdint2

all: $(TARGETS)


# Link the object files:

cmdint2: cmdint.o openhash.o
	$(CC) -o $@ cmdint.o openhash.o


# Compile the C++ files into object files

cmdint2.o: cmdint.cpp openhash.h
	$(CC) $(CFLAGS) cmdint.cpp 

openhash.o: openhash.cpp openhash.h
	$(CC) $(CFLAGS) openhash.cpp 


# Remove all non-critical files with the command: %make clean

clean:
	rm -f *.o *~* *.a
	rm -f cmdint
