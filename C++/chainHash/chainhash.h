#ifndef CHASH_H
#define CHASH_H

// chainhash.h - declaration file for ChainHash (chained hashing) class

using namespace std ;

#include "llist.h"

#define NIL 0
#define SIZE 10


class ChainHash {
public:
   LList * Array ;
   int m ;

   // Hash function h(k) = k mod m
   inline int h( int k ) { return k % m ; }

   // Constructor
   ChainHash( int mNew = SIZE ) ;

   // Hash table "dictionary" functions
   void CHinsert( NodePtr x ) ;
   void CHdelete( NodePtr x ) ;
   NodePtr CHsearch( KeyType key ) ;

   // LList display options
   void ShowTable( ) ;
} ;

#endif
