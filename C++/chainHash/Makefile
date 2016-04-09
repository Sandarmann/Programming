#################################################################
#
#  Makefile for hashing with chaining program, CS 4521, Fall 2009
#
#  Files:
#  cmdint.cpp       The main program
#
#  chainhash.h      The header file for the Chained Hash class
#  chainhash.cpp    The implemention file for the Chained Hash class
#
#  llist.h          The header file for the Linked List class
#  llist.cpp        The implemention file for the Linked List class
#
#  cmdint	    The executable program
#
#  Created by:      D. Dunham  October 31, 2009
#
##################################################################

CC = g++ 
DEBUG = -O

CFLAGS = $(DEBUG) -c

TARGETS = cmdint

all: $(TARGETS)


# Link the object files:

cmdint: cmdint.o chainhash.o llist.o
	$(CC) -o $@ cmdint.o chainhash.o llist.o


# Compile the C++ files into object files

cmdint.o: cmdint.cpp chainhash.h llist.h
	$(CC) $(CFLAGS) cmdint.cpp 

chainhash.o: chainhash.cpp chainhash.h
	$(CC) $(CFLAGS) chainhash.cpp 

llist.o: llist.cpp llist.h
	$(CC) $(CFLAGS) llist.cpp 


# Remove all non-critical files with the command: %make clean

clean:
	rm -f *.o *~* *.a
	rm -f cmdint
