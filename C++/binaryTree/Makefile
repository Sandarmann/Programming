#################################################################
#
#  Makefile for Binary Search Tree programs, CS 4521, Spring 2006
#
#  Files:
#  cmdint.cpp       The main program
#
#  bst.h            The header file for the Binary Search Tree class
#  bst.cpp          The implemention file for the Binary Search Tree class
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

cmdint: cmdint.o bst.o
	$(CC) -o $@ cmdint.o bst.o


# Compile the C++ files into object files

cmdint.o: cmdint.cpp bst.h
	$(CC) $(CFLAGS) cmdint.cpp 

bst.o: bst.cpp bst.h
	$(CC) $(CFLAGS) bst.cpp 


# Remove all non-critical files with the command: %make clean

clean:
	rm -f *.o *~* *.a
	rm -f cmdint
