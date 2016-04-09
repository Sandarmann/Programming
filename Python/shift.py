#!/usr/bin/env python

def shift(char, shift=0):
	charAsci = ord(char)
	return chr(((charAsci+shift) %96) + 96)


def print_factors(x):
   """This function takes a
   number and prints the factors"""

   print("The factors of",x,"are:")
   for i in range(1, x + 1):
       if x % i == 0:
           print(i)



print_factors(333)