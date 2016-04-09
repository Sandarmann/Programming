// driver.cpp - driver program to run Graph algorithms

#include "graph.h"
#include <iostream>
#include <string>

using namespace std ;


int main()
{
  int numVertices ;
  cin >> numVertices ;
  Graph G( numVertices, MATRIX, true ) ;
  cout << "Built graph, n = " << G.n << endl ;
  G.readEdges() ;

  cout << "\nRun Floyd-Warshall:\n" ;
  G.FloydWar() ;

  return 0;
}
