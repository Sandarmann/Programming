#ifndef GRAPH_H
#define GRAPH_H

// graph.h - declaration file for Graph structure
#include "pqueue.h"

using namespace std ;

#define NIL 0

enum Color { WHITE, GRAY, BLACK } ;


class Node {
public:
   int v ;
   int wuv ;
   Node * next ;
} ;


class Graph {
public:
   int n ;
   bool weighted ;

   Color * color ;
   int * pi ;
   int * d ; // = distance for BFS or discovery time for DFS
   int * f ; // = finish time for DFS
   Node ** Adj ;

// Constructor
   Graph( int size = 11, bool wgted = false ) ;
// : n(size),       weighted(wgted) ;

// Graph algorithm
   void dijkstra( int s ) ;

// Utility routines used for graph algoritms
   void initSingSrc( int s ) ;
   void relax( int u, int v, int w ) ;
   void readEdges() ;
   void printPath( int s, int v ) ;

// Utility routines - may be useful for debugging
   void showDists() ;
   void showPreds() ;
   void showAdj() ;
} ;

#endif