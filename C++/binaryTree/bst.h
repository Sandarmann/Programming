#ifndef BST_H
#define BST_H

// bst.h - declaration file for Binary Search Tree class

using namespace std ;

#define NULL 0
#define NIL 0

typedef int KeyType ; 

typedef class Node * NodePtr ;
// Note: One _could_ replace all "NodePtr"s below with "Node *"


class Node {
public:
   KeyType key ;
   NodePtr p ;
   NodePtr left ;
   NodePtr right ;

   // Constructor
   Node( KeyType k = 0 ) : key(k), p(NIL), left(NIL), right(NIL) {}
} ;


class BST {
   // Utilities 
   // This could be put in bst.cpp with "this" ptr as first arg
   void Transplant( NodePtr u, NodePtr v ) ;
   // inorderTreeWalk() could be made public if needed externally
   void inorderTreeWalk( NodePtr x ) ; 

public:
   NodePtr root ;

   // Constructor
   BST( ) : root(NIL) {}

   // BST "dictionary" functions
//   void BSTinsert( KeyType key ) ;
   void BSTinsert( NodePtr z ) ;
   void BSTdelete( NodePtr z ) ;
   NodePtr BSTsearch( NodePtr x, KeyType key ) ;

   // Other BST accessors - not directly used here
   NodePtr BSTmaximum(NodePtr x);
   NodePtr BSTminimum( NodePtr x ) ;
   NodePtr BSTsuccessor( NodePtr x ) ;

   // BST display options
   void ShowTree( NodePtr x, int depth ) ;
   void PrintTree( ) ;
} ;

#endif
