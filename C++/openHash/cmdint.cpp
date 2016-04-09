// cmdint.cpp - command interpreter program to test Open Hash module

#include "openhash.h"
#include <iostream>
#include <string>

using namespace std ;

int main()
{
  string comment ;
  char choice ;
  KeyType key, newKey ;
  int j ;
  OpenHash T(11) ;

  bool interact = true ;

  if ( interact ) cout << "Choose: (c)onstruct, (i)nsert, (d)elete, "
	  << "(s)earch, (S)how: " ;
  cin >> choice ;
  while ( !cin.eof() ) {
    switch ( choice ) {
      case 'c': 
		// This has already been done above.
		// Constructing within a switch causes scoping problems.
                break ;
      case 'i': 
                if ( interact ) cout << "Enter key value to insert: " ;
                cin >> newKey ;
                j = T.OHinsert( newKey ) ;
                if ( j != NIL ) {
                   cout << "key " << newKey << " inserted at index " << j
                        << endl ;
                } else {
                   // OHinsert reports hash table overflow
                } 
                break ;
      case 'd':
                if ( interact ) cout << "Enter key value to delete: " ;
                cin >> key ;
                j = T.OHdelete( key ) ;
		if ( j != NIL ) {
		   cout << "key " << key << " deleted from index " << j 
                        << endl ;
                } else {
		   cout << "No " << key << " key, can't delete" << "\n\n" ;
		}
                break ;
      case 's':
                if ( interact ) cout << "Enter key value to search for: " ;
                cin >> key ;
                j = T.OHsearch( key ) ;
		if ( j != NIL ) {
		   cout << "key " << key << " found at index " << j << endl ;
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

