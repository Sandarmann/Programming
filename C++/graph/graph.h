#ifndef GRAPH_H
#define GRAPH_H

// graph.h - declaration file for Graph structure

using namespace std ;

#define NIL 0

enum Color { WHITE, GRAY, BLACK } ;


// Should really use the linked list class, but we only need insert()
class Node {
public:
   int v ;
   int wuv ;
   Node * next ;
} ;


class Graph {
public:
   int n ;
   int INFINITY ;
   bool weighted ;

   Color * color ;
   int * pi ;
   int * d ; // = distance for BFS or discovery time for DFS
   int * f ; // = finish time for DFS
   Node ** Adj ;

// Constructor
   Graph( int size = 11, bool wgted = false, int inf = 1000 ) ;
// : n(size),       weighted(wgted),    INFINITY(inf) ;

// Graph algorithms
   void BFS( int s ) ;
   void DFS( int s ) ;

// Utility routines used for graph algoritms
   void DFSvisit( int u ) ;
   void readEdges() ;
   void printPath( int s, int v ) ;

// Utility routines - may be useful for debugging
   void showDists() ;
   void showPreds() ;
   void showAdj() ;
} ;

#endif
