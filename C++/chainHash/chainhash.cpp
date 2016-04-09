// chainhash.cpp implementation file for ChainHash chained hashing class

#include "chainhash.h"
#include <iostream>
#include <iomanip>


// Constructor 
ChainHash :: ChainHash( int mNew )
{
   m = mNew ;
   Array = new LList[m] ;
}


// ChainHash mutators
void ChainHash :: CHinsert( NodePtr x )
{
   int hval = h(x->key);
   Array[hval].LLinsert(x);
   // You insert the correct line here
}

void ChainHash :: CHdelete( NodePtr x )
{
    int hval = h(x->key);
    Array[hval].LLdelete(x);
   // You insert the correct line here
}

// ChainHash accessor
NodePtr ChainHash :: CHsearch( KeyType k )
{
   int hval = h(k);
   return Array[hval].LLsearch(k);
   // You insert the correct line here
}


/* Shows the structure of the list */
void ChainHash :: ShowTable( )
{
   cout << "Hash table:\n" ;
   for ( int i = 0 ; i < m ; i++ ) {
      cout << "T[" << i << "]: " ;
      Array[i].ShowList() ;
   }
   cout << "\n" ;
}

