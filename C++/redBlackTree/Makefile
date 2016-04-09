#################################################################
#
#  Makefile for Red-Black Tree program, CS 4521, Spring 2009
#
#  Files:
#  cmdint.cpp       The main program
#
#  rbtree.h         The header file for the Red-Black Tree class
#  rbtree.cpp       The implemention file for the Red-Black Tree class
#
#  cmdint	    The executable program
#
#  Created by:      D. Dunham  March 26, 2009
#
##################################################################

CC = g++ 
DEBUG = -O

CFLAGS = $(DEBUG) -c

TARGETS = cmdint

all: $(TARGETS)


# Link the object files:

cmdint: cmdint.o rbtree.o
	$(CC) -o $@ cmdint.o rbtree.o


# Compile the C++ files into object files

cmdint.o: cmdint.cpp rbtree.h
	$(CC) $(CFLAGS) cmdint.cpp 

rbtree.o: rbtree.cpp rbtree.h
	$(CC) $(CFLAGS) rbtree.cpp 


# Remove all non-critical files with the command: %make clean

clean:
	rm -f *.o *~* *.a
	rm -f cmdint
