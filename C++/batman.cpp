#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int X0;
int Y0;
double jumpDistanceY;
double jumpDistanceX;
int W; // width of the building.
int H; // height of the building.
int minW;
int minH;
//Need to have adaptive distances travelled because we can



/**
We could do this:
try to overshoot it,
if we overshoot the bomb then we cut the jump in half,
if we overshoot it again, we cut it in half again
keep doing this until we know where the bomb is

Try this box idea,
make a box with the direction you are given
then keep jumping to the center of said box, this will allow you to kind of triangulate the area.

TODO

With this box idea we need to adjust the W and H overall in order to have this actually triangualate because otherwise it will just continuously
jump around


should actually edit it so we have max and min x and y

*/
void jump(){

}


void direction(string previous){
    if(previous.find('U') != string::npos){
        H = Y0;
        cerr << "U" << endl;
        jumpDistanceY = ceil(((double)Y0 - (double)minH) /2);
        cerr << "jumpdist" << jumpDistanceY << endl;
        Y0 -= jumpDistanceY;   
    }
    else if(previous.find('D') != string::npos){
        minH = Y0;
        jumpDistanceY = ceil((((double) H - (double) Y0) / 2));
        cerr << "jumpdist" << jumpDistanceY << endl;
        Y0 += jumpDistanceY;
        cerr << "Y" << Y0 << endl;
        cerr << "D" << endl;
    }
    if(previous.find('R') != string::npos){
        minW = X0;
        jumpDistanceX = ceil((((double) W - (double) X0) / 2));
        cerr << "jumpdist" << jumpDistanceX << endl;
        cerr << "W" << W << endl;
        X0 +=jumpDistanceX;
        cerr << "R" << endl;
    }
    else if(previous.find('L') != string::npos){
        W = X0;
        jumpDistanceX = ceil(((double) X0 - (double) minW) / 2);
        X0 -= jumpDistanceX;
        cerr << "L" << endl;
    }
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    cin >> X0 >> Y0; cin.ignore();

    // game loop
    while (1) {
        string bomb; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bomb; cin.ignore();
        cerr << bomb << endl;
        cerr << "minH" << minH << endl;
        cerr << "minW" << minW << endl;
        
        direction(bomb);
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cout << X0 << " " << Y0 << endl; // the location of the next window Batman should jump to.
    }
}