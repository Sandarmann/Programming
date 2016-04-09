// llist.cpp implementation file for (doubly) linked list class

#include "llist.h"
#include <iostream>
#include <iomanip>


// Constructor - done in header file
// LList :: LList()
// {
//   head = NIL ;
// }


// LList mutators
void LList :: LLinsert( NodePtr x )
{
   x->next = head ;
   if ( head != NIL ) {
      head->prev = x ;
   }
   head = x ;
   x->prev = NIL ;
}

void LList :: LLdelete( NodePtr x )
{
   if ( x->prev != NIL ) {
      x->prev->next = x->next ;
   } else {
      head = x->next ;
   }
   if ( x->next != NIL ) {
      x->next->prev = x->prev ;
   }
}

// LList accessor
NodePtr LList :: LLsearch( KeyType k )
{
   NodePtr x = head ;
   while ( ( x != NIL ) && ( k != x->key ) ) {
      x = x->next ;
   }
   return x ;
}


/* Just prints list in order horizontally; may be used for debugging */
void LList :: PrintList( )
{
   cout << "List elements in order:\n" ;
   cout << "\n\n" ;
   NodePtr x = head ;
   while ( x != NIL ) {
      cout << x->key << "  " ;
      x = x->next ;
   }
   cout << "\n\n" ;
}

/* Shows the structure of the list */
void LList :: ShowList( )
{
   NodePtr x = head ;
   while ( x != NIL ) {
      cout <<  " -> " << x->key ;
      x = x->next ;
   }
   cout << " /\n" ;
}

