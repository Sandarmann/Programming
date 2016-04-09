// cmdint.cpp - command interpreter program to test Binary Search Tree module

#include "bst.h"
#include <iostream>
#include <string>

// Not needed here, but maybe to time other applications.
#include <time.h>

using namespace std ;

int main()
{
  string comment ;
  char choice ;
  KeyType key, newKey ;
  NodePtr x ;
  NodePtr y ;
  BST T ;

  bool interact = false ;
  bool printExtract = true ;

  if ( interact ) cout << "Choose: (c)onstruct, (i)nsert, (d)elete, "
	  << "(s)earch, (S)how, P(rint), " 
	  << "(m)inimum, (e)extract min, decrease (k)ey, "
	  << "+/- turns extract print on/off: " ; 
  cin >> choice ;
  while ( !cin.eof() ) {
    switch ( choice ) {
      case 'c': 
		// This has already been done above.
		// Calling a constructor within a switch causes problems.
                break ;
      case 'i': {
                if ( interact ) cout << "Enter key value to insert: " ;
                cin >> newKey ;
                NodePtr z = new Node( newKey ) ;
                T.BSTinsert( z ) ;
                } break ;
      case 'd':
                if ( interact ) cout << "Enter key value to delete: " ;
                cin >> key ;
                x = T.BSTsearch( T.root, key ) ;
		if ( x != NIL ) {
		   T.BSTdelete( x ) ;
                   delete x ;
                } else {
		   cout << "No " << key << " key, can't delete" << "\n\n" ;
		}
                break ;
      case 's':
                if ( interact ) cout << "Enter key value to search for: " ;
                cin >> key ;
                x = T.BSTsearch( T.root, key ) ;
		if ( x != NIL ) {
                   cout << "key, " << key << ", found" << "\n\n" ;
                } else {
		   cout << "key, " << key << ", not found" << "\n\n" ;
		}
                break ;

/*			This is not used directly in the tests
      case 'm': 
                z = T.BSTminimum() ;
                cout << "Minimum = " << key << "\n\n" ;
                break ;
*/
/*			The following two are not used in BST's
      case 'e': 
                if ( T.heapSize > 0 ) {
                   key = T.extractMin( ) ;
                   if ( printExtract ) 
                      cout << "Minimum extracted = " << key << "\n" ;
                } else {
                   cout << "Tree empty, can't extract minimum.\n\n" ;
                }
                break ;
      case 'k': 
                if ( interact ) cout << "Enter key to decrease and new key: " ;
                cin >> key >> newKey ;
                i = T.BSTsearch( key ) ;
                if ( i > 0 ) {
                   T.decreaseKey( i, newKey ) ;
		} else {
                   cout << "Originaly key = " << key << "not in heap.\n\n" ;
		}
                break ;
*/
      case 'S': 
		cout << "Structure of tree (rotated 90 degrees to left):\n\n" ;
		T.ShowTree( T.root, 0 ) ;
		cout << "\n\n" ;
                break ;
      case 'P': 
		T.PrintTree( ) ;
                break ;
/*
      case '+': 
		printExtract = true ;
                break ;
      case '-': 
		printExtract = false ;
                break ;
*/
      case '#': 
		cout << '#' ; getline(cin, comment) ;
                cout << comment << "\n\n" ;
                break ;
      default: 
		cout << "Illegal choice: " << choice << endl ;
    }
    if ( interact ) cout << "Choose: (c)onstruct, (i)nsert, (d)elete, "
	  << "(s)earch, (S)how, P(rint), " ;
//	  << "(m)inimum, (e)extract min, decrease (k)ey, "
//	  << "+/- turns extract print on/off: " ; 
    cin >> choice ;
  }
  cout << endl ;


  return 0;
}

