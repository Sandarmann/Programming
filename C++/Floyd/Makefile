#################################################################
#
#  Makefile for Graph programs, CS 4521, Spring 2002
#
#  Files:
#  driver.cpp       The main program
#
#  graph.h          The header file for the Graph class
#  graph.cpp        The implemention file for the Graph class
#
#  driver	    The executable program
#
#  Created by:      D. Dunham  March 24, 2002
#  Modified by:     D. Dunham  December 9, 2009
#
##################################################################

CC = g++ 
DEBUG = -O

CFLAGS = $(DEBUG) -c

TARGETS = driver

all: $(TARGETS)


# Link the object files:

driver: driver.o graph.o
	$(CC) -o $@ driver.o graph.o


# Compile the C++ files into object files

driver.o: driver.cpp graph.h
	$(CC) $(CFLAGS) driver.cpp 

graph.o: graph.cpp graph.h
	$(CC) $(CFLAGS) graph.cpp 


# Remove all non-critical files with the command: %make clean

clean:
	rm -f *.o *~* *.a
	rm -f driver