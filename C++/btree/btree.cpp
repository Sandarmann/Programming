// btree.cpp - implementation file for BTree structures

#include "btree.h"
#include <iostream>
#include <iomanip>


// Constructor
BTree :: BTree( )
{
   NodePtr x = new BTreeNode ;
   x->leaf = true ;
   x->n = 0 ;
   root = x ;
}


// Utility routines for insertion
void copy( NodePtr src, int startSrc, NodePtr dest, int startDest )
{
   int j, offset ;

   offset = startDest - startSrc ;
   for ( j = startSrc ; j < startSrc + t - 1 ; j++ ) {
      dest->key[j + offset] = src->key[j] ;
   }
   if ( !src->leaf ) {
       for ( j = startSrc ; j < startSrc + t ; j++ ) {
          dest->c[j + offset] = src->c[j] ;
       }
   }
}

void shiftUp( NodePtr x, int kStart, int cStart )
{
   for(int j = x->n; j>=kStart; j--){
    x->key[j+1] = x->key[j];
   }
   if(!x->leaf){
    for(int j=x->n+1; j>= cStart; j--){
      x->c[j+1] = x->c[j];
    }
   }
   x->n = x->n+1;
}

void shiftDown( NodePtr x, int kStart, int cStart )
{
   for(int j = kStart; j <= x->n; j++){
    x->key[j-1] = x->key[j];
   }
   if(!x->leaf){
    for(int j=cStart; j <= x->n+1; j++){
      x->c[j-1] = x->c[j];
    }
   }
   x->n = x->n-1;
}

void split_child( NodePtr x, int i )
{
   NodePtr z = new BTreeNode ;
   NodePtr y = x->c[i] ;

   z->leaf = y->leaf;
   z->n = t -1;
   // for (int j =1; j<t; j++){
   //  z->key[j] = y->key[j+t];
   // }   
   // if(!y->leaf){
   //  for(int j = 1; j<=t; j++){
   //    z->c[j] = y->c[j+t];
   //  }
   // }
   copy(y, t+1, z, 1);
   y->n = t-1;
   shiftUp(x,i,i+1);
   // for(int j=x->n+1; j> i; j--){
   //  x->c[j+1] = x->c[j];
   // }
   x->c[i+1] = z;
   // for(int j = z->n; j>=i; j--){
   //  x->key[j+1] = x->key[j];
   // }
   x->key[i] = y->key[t];
   // x->n = x->n+1;
}

int iLoc( NodePtr x, KeyType k )
{
   int i = 1 ;
   while ( i <= x->n && k > x->key[i] )
      i++ ;
   return i ;
}

void insert_nonfull( NodePtr x, KeyType k )
{
   int i = iLoc( x, k ) ;
   if ( x->leaf ) {
       shiftUp( x, i, i) ;
       x->key[i] = k ;
   } else {
    if(x->c[i]->n == 2*t-1){
      split_child(x,i);
      if(k>x->key[i]){
        i ++;
      }
    }
    insert_nonfull(x->c[i], k);
   }
}

void BTree :: BTinsert( KeyType k )
{
  NodePtr r = root;
  if(r->n == 2*t-1){
       NodePtr s = new BTreeNode ;
       root = s;
       s->leaf = false;
       s->n = 0;
       s->c[1] = r;
       split_child(s,1);
       insert_nonfull(s,k);
  }
  else{
    insert_nonfull(r,k);
  }
}


// Utility routines for deletion
KeyType minimum( NodePtr x )
{
  while (!x->leaf){
    x = x->c[1];
  }  
  return x->key[1];
}

KeyType maximum( NodePtr x ) //FIX DISSSSSSSS
{
   while (!x->leaf){
    x = x->c[x->n]; //get the max of the current array
  }  
  return x->key[x->n];
}

void borrowLeft( NodePtr x, int i )
{
   NodePtr y = x->c[i-1] ;
   NodePtr z = x->c[i] ;

   shiftUp( z, 1, 1 ) ;

   z->key[1] = x->key[i-1];
   x->key[i-1] = y->key[y->n];
   z->c[1] = y->c[y->n+1];
   y->n = y->n -1;

}

void borrowRight( NodePtr x, int i )
{
   NodePtr y = x->c[i] ;
   NodePtr z = x->c[i+1] ;

   y->key[y->n+1] = x->key[i];
   x->key[i] = z->key[1];
   y->c[y->n+2] = z->c[1];
   y->n = y->n +1;

   shiftDown( z, 2, 2 ) ;
}

void merge_children( NodePtr x, int i )
{
   NodePtr y = x->c[i] ;
   NodePtr z = x->c[i+1] ;

   copy ( z, 1, y, t+1 ) ;

   y->key[t] = x->key[i]; // move splitting key down
   y->n = (2*t)-1; //y is now a full node
   
   shiftDown( x, i+1, i+2 ) ;

   delete z ;
}


void delete_fullenuf( NodePtr x, KeyType k )
{
   int i = iLoc( x, k ) ;
   KeyType k_prime ;
   // cout << "delete fullenuf" << endl;
   // cout << "i: " << i << endl;
   // cout << "x->n: " << x->n << endl;
   // cout << "k: " << k << endl;
   // cout << "key[i] : " << x->key[i] << endl;
   if (x->leaf) {
      // cases "0." and 1.
      if (i <= x->n && x->key[i] == k){
        shiftDown(x, i+1, i+1);
      }
      else{
        cout << "no K found" << endl;
      }
   } else {

        if(i <= x->n && x->key[i] == k){
          if(x->c[i]->n >= t){
            // cout << "Case 2A" << endl;
            k_prime = maximum(x->c[i]);
            x->key[i] = k_prime;
            delete_fullenuf(x->c[i], k_prime);
          }
          else if (x->c[i+1]->n >= t){
            // cout << "Case 2B" << endl;
            k_prime = minimum(x->c[i+1]);
            x->key[i] = k_prime;
            delete_fullenuf(x->c[i+1], k_prime);
          }else{
            // cout << "Case 2C" << endl;
             merge_children(x,i);
             delete_fullenuf(x->c[i], k);
          }
        } else {
            if(x->c[i]->n < t){
              // cout << "case 3" << endl;

              if(i>1 && x->c[i-1]->n >=t){  //case 3a SOMETHING WACKY IS GOING ON HERE
                // cout << "x->c[i-1]->n: " << x->c[i-1]->n << endl;
                // cout << "case 3A1" << endl;
                //    cout << "x->n: " << x->n << endl;
                borrowLeft(x,i);

              }
              else if(i <= x->n && x->c[i+1]->n >= t){ //case 3b
                // cout << "case 3A2" << endl;
                borrowRight(x,i);
              }
              else{ //case 3c

                // cout << "case 3B" << endl;
                if(i == x->n+1){
                  i = i-1;
                }
                merge_children(x,i);
              }

            }
            delete_fullenuf(x->c[i], k);
        }
   }
}

void BTree :: BTdelete( KeyType k )
{
   NodePtr r = root ;
   if ( r->n == 0 ) {
       cout << "Deleting from empty tree.\n" ;
   } else {
       delete_fullenuf ( r, k ) ;
       if ( r->n == 0 && !r->leaf ) {
           root = r->c[1] ;
           delete r ;
       }
   }
}


BTreeLocation BTree :: BTsearch( NodePtr x, KeyType k )
{
   int i = iLoc( x, k ) ;
   if ( i <= x->n && k == x->key[i] )
       return BTreeLocation( x, i ) ;
   if ( x->leaf ) {
       return BTreeLocation( NIL, 0 ) ;
   } else {
       return BTsearch(x->c[i], k);
   }
}


// Useful routine to show B-Tree structure
void BTree :: ShowTree( NodePtr x, int depth )
{
   if ( x->leaf ) {
       for ( int i = x->n ; i >= 1 ; i-- ) {
          cout << setw( depth*6 + 7 ) << x->key[i] << endl ;
       }
   } else {
       ShowTree( x->c[x->n + 1], depth + 1 ) ;
       for ( int i = x->n ; i >= 1 ; i-- ) {
          cout << setw( depth*6 + 7 ) << x->key[i] << endl ;
          ShowTree( x->c[i], depth + 1 ) ;
       }
   }
}


// Useful routine to show a single node
void BTreeNode :: ShowNode()
{
   cout << "\nLeaf = " << ( ( leaf )? "True" : "False" )
        << ", n = " << n << "\nKeys: " ;
   for ( int i = 1 ; i <= n ; i++ )
      cout << key[i] << ' ' ;
   cout << "\n\n" ;
}

