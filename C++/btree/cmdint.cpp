// cmdint.cpp - command interpreter program to test BTree module

#include "btree.h"
#include <iostream>
#include <iomanip>
#include <string>


int main()
{
  string comment ;
  char choice ;
  KeyType key ;
  BTree T ;
  BTreeLocation loc ;

  bool interact = true ;
  

  if ( interact )  cout << "Choose: c(reate), i(nsert), d(elete), s(earch), "
                        << "S(how), or # (for a comment): " ; 
  cin >> choice ;
  while ( !cin.eof() ) {
    switch ( choice ) {
      case 'c': // This has been done above
                break ;
      case 'i': 
                if ( interact ) cout << "Enter key value to insert: " ;
                cin >> key ;
                T.BTinsert( key ) ;
                break ;
      case 'd': 
                if ( interact ) cout << "Enter key value to delete: " ; 
                cin >> key ;
                T.BTdelete( key ) ;
                break ;
      case 's': 
                if ( interact ) cout << "Enter key value to search for: " ; 
                cin >> key ;
                loc = T.BTsearch( T.root, key ) ;
                if ( loc.x != NIL ) {
                    cout << "Key " << key << " found at index "
                         << loc.index << " in node:\n" ;
                    loc.x->ShowNode() ;
                } else {
                    cout << "Key " << key << " not found\n\n" ;
                }
                break ;
      case 'S':
                cout << "Structure of BTree (rotated 90 degrees to the left):"
                     << "\n\n" ;
                T.ShowTree( T.root, 0 ) ;
                cout << endl ;
                break ;
      case '#': cout << '#' ; getline(cin, comment) ;
                cout << comment << endl ;
                break ;
      default: cout << "Illegal choice: " << choice << endl ;
    }
    if ( interact ) cout << "Choose: c(reate), i(nsert), d(elete), s(earch), "
                         << "S(how), or # (for a comment): " ;
    cin >> choice ;
  }
  cout << endl ;

  return 0;
}

