#ifndef BTREE_H
#define BTREE_H

// btree.h - declaration file for BTree structure

using namespace std ;

#define NIL 0

const int t = 3;

typedef int KeyType ; 

class BTreeNode {
public:
   bool leaf ;
   int n ;
   KeyType key[2*t] ;
   BTreeNode * c[2*t + 1] ;

   void ShowNode() ;
} ;

typedef BTreeNode * NodePtr ;

class BTreeLocation {
public:
   NodePtr x ;
   int index ;

   BTreeLocation( NodePtr ptr = NIL, int i = 0 ) : x(ptr), index(i) { }
} ;

class BTree {
public:
   NodePtr root ;

// Constructor
   BTree( ) ;

   void BTinsert( KeyType k ) ;
   void BTdelete( KeyType k ) ;
   BTreeLocation BTsearch( NodePtr x, KeyType k ) ;

   void ShowTree( NodePtr x, int depth ) ;
} ;

#endif
