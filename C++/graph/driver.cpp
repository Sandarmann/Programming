// driver.cpp - driver program to run Graph algorithms

#include "graph.h"
#include <iostream>
#include <string>

using namespace std ;


int main()
{
  int numVertices, source ;
  cin >> numVertices ;
  Graph G( numVertices, false, 1000 ) ;
  G.readEdges() ;
// The following may be useful for debugging
//  cout << "Built graph, n = " << G.n << "\n\n" ;
//  G.showAdj() ; 

  cout << "Run BFS:\n\n" ;
  cout << "BFS, source = 1, destination = 12:\n\n" ;
  G.BFS( 1 ) ;
  G.printPath( 1, 12 ) ; cout << "\n\n" ;

  cout << "BFS, source = 12, destination = 1:\n\n" ;
  G.BFS( 12 ) ;
  G.printPath( 12, 1 ) ; cout << "\n\n" ;

  cout << "BFS, source = 1, destination = 4:\n\n" ;
  G.BFS( 1 ) ;
  G.printPath( 1, 4 ) ; cout << "\n\n" ;

  cout << "BFS, source = 4, destination = 1:\n\n" ;
  G.BFS( 4 ) ;
  G.printPath( 4, 1 ) ; cout << "\n\n" ;

  cout << "Run DFS:\n\n" ;
  cout << "DFS, source = 1, destination = 12:\n\n" ;
  G.DFS( 1 ) ;
  G.printPath( 1, 12 ) ; cout << "\n\n" ;

  cout << "DFS, source = 12, destination = 1:\n\n" ;
  G.DFS( 12 ) ;
  G.printPath( 12, 1 ) ; cout << "\n\n" ;

  cout << "DFS, source = 1, destination = 4:\n\n" ;
  G.DFS( 1 ) ;
  G.printPath( 1, 4 ) ; cout << "\n\n" ;

  cout << "DFS, source = 4, destination = 1:\n\n" ;
  G.DFS( 4 ) ;
  G.printPath( 4, 1 ) ; cout << "\n\n" ;

  return 0;
}

