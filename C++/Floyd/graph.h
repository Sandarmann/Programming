#ifndef GRAPH_H
#define GRAPH_H

// graph.h - declaration file for Graph structure

using namespace std ;

#define INFINITY 99
#define NIL 0
#define ADD(p,q) ((( p == INFINITY ) || ( q == INFINITY )) ? INFINITY : p + q )

enum RepType { ADJ_LIST, MATRIX } ;
enum Color { WHITE, GRAY, BLACK } ;


// Node class is used for adjacency list representation
class Node {
public:
   int v ;
   int wuv ;
   Node * next ;
} ;


class Graph {
public:
   int n ;
   RepType representation ;
   bool weighted ;
   Node ** Adj ;   // for adjacency list representation
   int ** W ;      // for adjacency matrix representation

   Color * color ; // for BFS or DFS algorithm
   int * pi ;      // predecessor array for BFS or DFS
   int * d ;       // = distance for BFS or discovery time for DFS
   int * f ;       // = finish time for DFS
   int ** D ;      // distance estimate for Floyd-Warshall
   int ** PI ;     // predecessor matrix for Floyd-Warshall

// Constructor
   Graph( int size = 11, RepType rep = ADJ_LIST, bool wgted = false ) ;
// : n(size),       representation(rep),    weighted(wgted) ;

// Graph algorithms
//   BFS not implemented here - needs a queue
//   void BFS( int s ) ;
   void DFS( int s ) ;
   void FloydWar() ;

// Utility routines used for graph algoritms
   void readEdges() ;
   void DFSvisit( int u ) ;
   void initSingSrc( int s ) ; // used in Dijkstra's algorithm
   void relax( int u, int v, int w ) ; // used in Dijkstra's algorithm
   void initFloydWar( ) ;
   void printPath( int s, int v ) ; // used in single source algorithms
   void showDandPI( int k ) ;  // for Floyd-Warshall

// Utility display routines - may be useful for debugging
   void showW() ;
   void showDists() ;
   void showPreds() ;
   void showAdj() ;
} ;

#endif