#ifndef OHASH_H
#define OHASH_H

// openhash.h declaration file for OpenHash open address hashing class

using namespace std ;

// In order to distinguish between array index 0 and NIL, set NIL to -1
#define NIL -1
#define DELETED -2
#define SIZE 10

typedef int KeyType ;


class OpenHash {
public:
   KeyType * Array ;
   int m ;

   // Hash function h(k,i) = ((k mod m) + i) mod m
   inline int h( KeyType k, int i ) { return (k%m + i) % m ; }

   // Constructor
   OpenHash( int mNew = SIZE ) ;

   // Hash table "dictionary" functions
   int OHinsert( KeyType key ) ;
   int OHdelete( KeyType key ) ;
   int OHsearch( KeyType key ) ;

   // LList display options
   void ShowTable( ) ;
} ;

#endif
