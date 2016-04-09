// graph.cpp - implementation file for Graph structure

#include "graph.h"
#include <iostream>
#include <iomanip>
// queue.h is needed for BFS

// using namespace std ;


// Constructor
Graph :: Graph( int size , bool wgted )
{
   int i, j ;

   n = size ;
   weighted = wgted ;
   color = new Color[ n+1 ] ;
   pi = new int[ n+1 ] ;
   d = new int[ n+1 ] ;
   f = new int[ n+1 ] ;
   Adj = new Node*[ n+1 ] ;
   for ( i = 1 ; i <= n ; i++ ) {
      Adj[i] = NIL ;
   }
}


// Internal utility routines for Dijkstra's algorithm
void Graph :: initSingSrc( int s )
{
  for(int i=1; i<=n; i++){
    d[i] = 1000;
    pi[i] = NIL;
  }
  d[s] = 0;

}

PQueue Q ;  // Priority queue used in Dijkstra's algorithm

void Graph :: relax( int u, int v, int w )
{
   if ( d[v] > d[u] + w ) {
    d[v] = d[u] + w;
    Q.decreaseKey(v, d[u] + w); 
    pi[v] = u;
   }
}


void Graph :: dijkstra( int source )
{
  initSingSrc( source ) ;
  Q = PQueue(n+1);
  for ( int v = 1 ; v <= n ; v++ ) {
    Q.insert(d[v]);
  }
  for ( int i = 1 ; i <= n ; i++ ) {
    int u = Q.extractMin() ;
    Node* node = Adj[u];
    while(node){
      relax(u, node->v, node->wuv);
      node = node->next;
    }
// You write the "for all v in Adj[u]" loop

     cout << "Iteration " << i << ", " ;
     showDists() ;
  }
  cout << "Final distances and predecessors:\n\n" ;
  showDists() ;
  showPreds() ;
}


// Useful external utility routines
void Graph :: readEdges()
{
   int u, v, wt ;

   if ( weighted ) cin >> u >> v >> wt ;
   else            cin >> u >> v ; 
   while ( !cin.eof() ) {
      Node * x = new Node ;
      x->v = v ;
      if ( weighted ) x->wuv = wt ;
      x->next = Adj[u] ;
      Adj[u] = x ;
      if ( weighted ) cin >> u >> v >> wt ;
      else            cin >> u >> v ; 
   } // while ( !cin.eof() ) ;
}

void Graph :: printPath( int s, int v )
{
   if ( v == s ) {
      cout << s ;
   } else {
      if ( pi[v] == NIL ) {
         cout << "No path from " << s << " to " << v << " exists\n" ;
      } else { 
         printPath( s, pi[v] ) ;
         cout << " -> " << v ;
      }
   }
}

void Graph :: showDists()
{
   cout << "Distances" ;
   for ( int v = 1 ; v <= n ; v++ ) {
      cout << ", d[" << v << "] = " << d[v] ; 
   }
   cout << "\n\n" ;
}

void Graph :: showPreds()
{
   cout << "Predecessors" ;
   for ( int v = 1 ; v <= n ; v++ ) {
      cout << ", pi[" << v << "] = " << pi[v] ; 
   }
   cout << "\n\n" ;
}

void Graph :: showAdj()
{
   cout << "The Adjacency lists:\n" ;
   for ( int v = 1 ; v <= n ; v++ ) {
      cout << "Adj[" << v << "]" ; 
      for ( Node * x = Adj[v] ; x != NIL ; x = x->next ) {
         cout << "->[" << x->v ;
         if ( weighted ) cout << "," << x->wuv ;
         cout << "]" ;
      }
/*
      Node * x = Adj[v] ;
      while ( x != NIL ) {
         cout << "->[" << x->v ;
         if ( weighted ) cout << "," << x->wuv ;
         cout << "]" ;
         x = x->next ;
      }
*/
      cout << endl ;
   }
   cout << "\n\n" ;
}
