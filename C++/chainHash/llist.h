#ifndef LLIST_H
#define LLIST_H

// llist.h - declaration file for LList (doubly linked list) class

using namespace std ;

#define NULL 0
#define NIL 0

typedef int KeyType ; 

typedef class Node * NodePtr ;
// Note: One _could_ replace all "NodePtr"s below with "Node *"


class Node {
public:
   KeyType key ;
   NodePtr next ;
   NodePtr prev ;

   // Constructor
   Node( KeyType k = 0 ) : key(k) {}
} ;


class LList {
public:
   NodePtr head ;

   // Constructor
   LList( ) { head = NIL ; }

   // Linked list "dictionary" functions
   void LLinsert( NodePtr x ) ;
   void LLdelete( NodePtr x ) ;
   NodePtr LLsearch( KeyType key ) ;

   // LList display options
   void ShowList( ) ;
   void PrintList( ) ;
} ;

#endif
