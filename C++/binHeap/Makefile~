#################################################################
#
#  Makefile for Binary Heap programs, CS 5521, Spring 2006
#
#  Files:
#  cmdint.cpp       The main program
#
#  binheap.h        The header file for the Binary Heap class
#  binheap.cpp      The implemention file for the Binary Heap class
#
#  cmdint	    The executable program
#
#  Created by:      D. Dunham  March 24, 2002, modified Feb. 12, 2006
#
##################################################################

CC = g++
DEBUG = -O

CFLAGS = $(DEBUG) -c

TARGETS = cmdint

all: $(TARGETS)


# Link the object files:

cmdint: cmdint.o binheap.o
	$(CC) -o $@ cmdint.o binheap.o


# Compile the C++ files into object files

cmdint.o: cmdint.cpp binheap.h
	$(CC) $(CFLAGS) cmdint.cpp

binheap.o: binheap.cpp binheap.h
	$(CC) $(CFLAGS) binheap.cpp


# Remove all non-critical files with the command: %make clean

clean:
	rm -f *.o *~* *.a
	rm -f cmdint
