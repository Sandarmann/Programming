// driver.cpp - driver program to run Dijkstra algorithm

#include "graph.h"
#include <iostream>
#include <string>

using namespace std ;


int main()
{
  int numVertices, source ;
  cin >> numVertices >> source ;
  Graph G( numVertices, true ) ;
  cout << "Built graph, n = " << G.n << "\n\n" ;
  G.readEdges() ;
// The following may be useful for debugging.
  G.showAdj() ; 

  cout << "Run Dijkstra with source = " << source << "\n\n" ;
  G.dijkstra( source ) ;

  return 0;
}
