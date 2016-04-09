#################################################################
#
#  Makefile for B-tree programs, CS 4521, Spring 2002
#
#  Files:
#  cmdint.cpp       The main testing program
#
#  btree.h          The header file for the B-tree class
#  btree.cpp        The implemention file for the B-tree class
#
#  cmdint	    The executable program
#
#  Created by:      D. Dunham  March 24, 2002
#  Modified by:     D. Dunham  November 6, 2009
#
##################################################################

CC = g++ 
DEBUG = -O

CFLAGS = $(DEBUG) -c

TARGETS = cmdint

all: $(TARGETS)


# Link the object files:

cmdint: cmdint.o btree.o
	$(CC) -o $@ cmdint.o btree.o


# Compile the C++ files into object files

cmdint.o: cmdint.cpp btree.h
	$(CC) $(CFLAGS) cmdint.cpp 

btree.o: btree.cpp btree.h
	$(CC) $(CFLAGS) btree.cpp 


# Remove all non-critical files with the command: %make clean

clean:
	rm -f *.o *~* *.a
	rm -f cmdint
