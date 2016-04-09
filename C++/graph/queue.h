#ifndef QUEUE_H
#define QUEUE_H

// queue.h - declaration file for Queue data structure

using namespace std ;

typedef int ElementType ;

class Queue {
public:
   int length ;
   int head ;
   int tail ;

   int * Array ;

// Constructor
   Queue( int len = 10 ) ;
// : length(len) ;

   void enqueue( ElementType x ) ;
   ElementType dequeue( ) ;
   bool empty( ) ;

// Utility routine - may be useful for debugging
// void showQueue() ;

} ;

#endif
