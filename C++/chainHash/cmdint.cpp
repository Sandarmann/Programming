// cmdint.cpp - command interpreter program to test Chained Hash module

#include "chainhash.h"
#include <iostream>
#include <string>

using namespace std ;

int main()
{
  string comment ;
  char choice ;
  KeyType key, newKey ;
  NodePtr x ;
  ChainHash T(9) ;

  bool interact = true ;

  if ( interact ) cout << "Choose: (c)onstruct, (i)nsert, (d)elete, "
	  << "(s)earch, (S)how: " ;
  cin >> choice ;
  while ( !cin.eof() ) {
    switch ( choice ) {
      case 'c': 
		// This has already been done above.
		// Constructing L within a switch causes scoping problems.
                break ;
      case 'i': 
                if ( interact ) cout << "Enter key value to insert: " ;
                cin >> newKey ;
                {
                  NodePtr x = new Node ;
                  x->key = newKey ;
                  T.CHinsert( x ) ;
                }
                break ;
      case 'd':
                if ( interact ) cout << "Enter key value to delete: " ;
                cin >> key ;
                x = T.CHsearch( key ) ;
		if ( x != NIL ) {
		   T.CHdelete( x ) ;
//                   delete x ;
                } else {
		   cout << "No " << key << " key, can't delete" << "\n\n" ;
		}
                break ;
      case 's':
                if ( interact ) cout << "Enter key value to search for: " ;
                cin >> key ;
                x = T.CHsearch( key ) ;
		if ( x != NIL ) {
                   cout << "key, " << key << ", found" << "\n\n" ;
                } else {
		   cout << "key, " << key << ", not found" << "\n\n" ;
		}
                break ;
      case 'S': 
		cout << "Structure of Table:\n\n" ;
		T.ShowTable( ) ;
		cout << "\n\n" ;
                break ;
      case '#': 
		cout << '#' ; getline(cin, comment) ;
                cout << comment << "\n\n" ;
                break ;
      default: 
		cout << "Illegal choice: " << choice << endl ;
    }
    if ( interact ) cout << "Choose: (c)onstruct, (i)nsert, (d)elete, "
	  << "(s)earch, (S)how: " ;
    cin >> choice ;
  }
  cout << endl ;

  return 0;
}

