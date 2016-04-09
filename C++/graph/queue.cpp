// queue.cpp - implementation file for Queue Data structure

// NOTE: there is no error-checking for overflow or underflow

#include "queue.h"
#include <iostream>
#include <iomanip>

// using namespace std ;


Queue :: Queue( int len )
{
   length = len ;
   head = 1 ;
   tail = 1 ;

   Array = new ElementType[ length+1 ] ;
}


void Queue :: enqueue( ElementType x )
{
   Array[tail] = x ;
   if ( tail == length ) tail = 1 ;
   else                  tail++ ;
}

ElementType Queue :: dequeue( )
{
   ElementType x = Array[head] ;
   if ( head == length ) head = 1 ;
   else                  head++ ;
   return x ;
}

bool Queue :: empty( )
{
   return ( head == tail ) ;
}


/*
void Queue :: showQueue()
{
   cout << "The contents of the queue:\n" ;
//  This has not been implemented, but may be useful for debugging
}
*/

