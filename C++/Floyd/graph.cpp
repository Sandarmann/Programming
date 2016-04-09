// graph.cpp - implementation file for Graph structure

#include "graph.h"
#include <iostream>
#include <iomanip>

// using namespace std ;


Graph :: Graph( int size , RepType rep, bool wgted )
{
   n = size ;
   representation = rep ;
   weighted = wgted ;

   if ( representation == ADJ_LIST ) {
      Adj = new Node*[ n+1 ] ;
      for ( int i = 1 ; i <= n ; i++ ) {
         Adj[i] = NIL ;
      }
   } else {  // representation == MATRIX
      W = new int*[ n+1 ] ;
      for ( int i = 1 ; i <= n ; i++ ) {
         W[i] = new int[ n+1 ] ;
      }
   } 

   color = new Color[ n+1 ] ;
   pi = new int[ n+1 ] ;
   d = new int[ n+1 ] ;
   f = new int[ n+1 ] ;
}


// Utility routines to support Floyd-Warshall algorithm
void Graph :: initFloydWar()
{
// Create the arrays D[][] and PI[][]
   D = new int*[ n+1 ] ;
   for ( int i = 1 ; i <= n ; i++ ) {
      D[i] = new int[ n+1 ] ;
   }
   PI = new int*[ n+1 ] ;
   for ( int i = 1 ; i <= n ; i++ ) {
      PI[i] = new int[ n+1 ] ;
   }
   for (int i=1; i<=n; i++){
      for (int j=1; j<=n; j++){
          D[i][j] = W[i][j];
          if(i == j || W[i][j] == INFINITY){
            PI[i][j] = NIL;
          } else{
            PI[i][j] = i;
          }
      }
   }
// You need to do two things: (1) copy W to D, (2) intialize PI
// To intialize PI, PI[i][j] should be NIL if W[i][j] = 0 or INFINITY
// otherwise PI[i][j] should be i   
}

void Graph :: showDandPI( int k )
{
// This is messy - and is done for you
  int i, j ;
  cout << "\nD(" << k << ") =" ;
  for ( j = 1 ; j <= 3*n + 1 ; j++ ) cout << ' ' ;
  cout << "PI(" << k << ") =\n\n" ;
  for ( i = 1 ; i <= n ; i++ ) {
    cout << "|" ;
    for ( j = 1 ; j <= n ; j++ ) {
      cout << setw(2) << D[i][j] << " " ;
    }
    cout << "|     |" ;
    for ( j = 1 ; j <= n ; j++ ) {
      cout << setw(2) << PI[i][j] << " " ;
    }
    cout << "|\n" ;
  }
}


void Graph :: FloydWar()
{
  initFloydWar() ;
  showDandPI( 0 ) ;

  for ( int  k = 1 ; k <= n ; k++ ) {
    // Update the D and PI arrays allowing for new intermediate vertex k
    for (int i=1; i<=n; i++){
      for (int j=1; j<=n; j++){
        if(D[i][k] + D[k][j] < D[i][j]){
          D[i][j] = D[i][k] + D[k][j];
          PI[i][j] = PI[k][j];
        }
      }
    }
    showDandPI( k ) ;
  }
}


/* Not implemented since it needs a queue
void Graph :: BFS( int s )
{
   for ( int u = 1 ; u <= n ; u++ ) {
      color[u] = WHITE ;
      d[u] = INFINITY ;
      pi[u] = NIL ;
   }
   color[s] = GRAY ;
   d[s] = 0 ;
   pi[s] = NIL ;

   Queue Q ;
   Q.enqueue( s ) ;
   while ( !Q.empty() ) {
      int u = Q.dequeue() ;
      for ( Node * x = Adj[u] ; x != NIL ; x = x->next ) {
         int v = x->v ; 
         if ( color[v] == WHITE ) {
            color[v] = GRAY ;
            d[v] = d[u] + 1 ;
            pi[v] = u ;
            Q.enqueue( v ) ;
         }
      }
      color[u] = BLACK ;
   }
}
*/

int dfsTime ; // Global variable used in Depth-First Search
// Use this instead of time to avoid conflict with system time() 

void Graph :: DFSvisit( int u )
{
   color[u] = GRAY ;
   d[u] = dfsTime = dfsTime + 1 ;
   for ( Node * x = Adj[u] ; x != NIL ; x = x->next ) {
      int v = x->v ; 
      if ( color[v] == WHITE ) {
         pi[v] = u ;
         DFSvisit( v ) ;
      }
   }
   color[u] = BLACK ;
   f[u] = dfsTime = dfsTime + 1 ;
}

void Graph :: DFS( int s )
{
   for ( int u = 1 ; u <= n ; u++ ) {
      color[u] = WHITE ;
      pi[u] = NIL ;
   }
   dfsTime = 0 ;
   DFSvisit( s ) ;
}


void Graph :: initSingSrc( int s )
{
   for ( int v = 1 ; v <= n ; v++ ) {
      d[v] = INFINITY ;
      pi[v] = 0 ;
   }
   d[s] = 0 ;
}

void Graph :: relax( int u, int v, int w )
{
   if ( d[v] > d[u] + w ) {
     d[v] = d[u] + w ;
     pi[v] = u ;
   }
}


void Graph :: readEdges()
{
   int u, v, wt ;

   if ( representation == ADJ_LIST ) {
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
   } else {  // representation == MATRIX
      // Assumes adjacency/weight matrix is an nxn array
      for ( int i = 1 ; i <= n ; i++ ) {
          for ( int j = 1 ; j <= n ; j++ ) {
              cin >> W[i][j] ;
          }
      }
   } 
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

void Graph :: showW()
{
   cout << "The weight matrix:\n" ;
   for ( int j = 1 ; j <= 3*n + 1 ; j++ ) cout << ' ' ;
   cout << "W(" << 0 << ") =\n\n" ;
   for ( int i = 1 ; i <= n ; i++ ) {
     cout << "|" ;
     for ( int j = 1 ; j <= n ; j++ ) {
       cout << setw(2) << W[i][j] << " " ;
     }
     cout << "|\n" ;
   }
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
      cout << endl ;
   }
   cout << "\n\n" ;
}
