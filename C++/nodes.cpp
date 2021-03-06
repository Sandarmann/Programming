#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
    }
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
    }

    // game loop
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cout << "0 1" << endl; // Example: 0 1 are the indices of the nodes you wish to sever the link between
    }
}

// Gateway
    
// For each test you are given:

//     A map of the network.
//     The position of the exit gateways.
//     The starting position of the Skynet agent.

// >>> Nodes can only be connected to up to a single gatweway. <<<


// Each game turn:

//     First off, you sever one of the given links in the network.
//     Then the Skynet agent moves from one Node to another accessible Node.

 
 
// The game is over when :

//     The Skynet agent cannot reach an exit gateway: mission successfully completed :)
//     The Skynet agent has reached a gateway: mission failed :(

//  