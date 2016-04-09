#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
/*
*	Thinking is that we should be able to make a cell that allows us to do some things with our code. Like allow searching and what not. But we will see
*
*/
class Cell{
	public:
		//We can use the generic constructor to create the bad spots
		Cell(){
		}
	    
	    // Cell(Cell& c){
	    //     position = c.position;
	    //     element = c.element;
	    //     isVisited = c.isVisited;
	    //     isExplorable = c.isExplorable;
	    // }
		//This will be to let us create the 
		Cell(char c){
			element = c;
			isVisited = false;
			setIsExplorable(c);
		}
		
		Cell(char c, int position, bool visited){
			element = c;
			isVisited = visited;
			setIsExplorable(c);
			this->position = position;
		}

		Cell(char c, int position, bool visited, int x, int y){
			element = c;
			isVisited = visited;
			setIsExplorable(c);
			this->position = position;
			this->x = x;
			this->y = y;
		}

		Cell(char c, int x, int y, bool visited){
			element = c;
			isVisited = visited;
			setIsExplorable(c);
			this->x = x;
			this->y = y;
		}
		
		int getPosition(){
		    return position;
		}
		void setIsExplorable(char c){
			if(c == '?' || c == '.' || c == 'T' || c == 'C'){
				isExplorable = true;
			}else{
				isExplorable = false;
			}
		}

		int getPositionColumn(){
			return x;
		}

		int getPostionRow(){
			return y;
		}

		char getType(){
		    return element;
		}

		bool getVisited(){
			return isVisited;
		}

		bool getExplorable(){
			return isExplorable;
		}
		

	private:
		int x;
		int y;
		int position;
		char element;
		bool isVisited;
		bool isExplorable;
};

/**
So with this map we should be able to do all the necessary padding. The cells should not know about eachother and this will make it easier to check where everything is in relation to one
another. Hopefully this works better

*/

class Map{
	public:
		Map(){
		 isControlRoomVisible = false;
		 isControlRoomFound = false;
		}

		//I Have now added hardcoded arrays so everythin will be in the proper area to reference for a direction
		// LEFT = 0
		//RIGht = 1
		//UP = 2
		//DOWN = 3
		vector<Cell> getNeighbors(){
			vector<Cell> neighbors(4);
			int pos =  getCurrentPosition();
			if(pos - 1 >= 0 ){
			    Cell cell = getCellAtPosition(pos - 1);
				neighbors[0] = cell;
			}
			if(pos + 1 < sizeX * sizeY){
			    Cell cell = getCellAtPosition(pos+1);
				neighbors[1] = cell;
			}
			if(pos - sizeX >= 0){			   
			    Cell cell = getCellAtPosition(pos-sizeX);
				neighbors[2] = cell;
			}
			if(pos+sizeX <= sizeX * sizeY){
			    Cell cell = getCellAtPosition(pos + sizeX);
				neighbors[3] = cell;
			}
			return neighbors;
		}

		bool compareToVisited(Cell c){
			bool result = false;
			vector<Cell>::iterator it = visited.begin();
	        //try to print from vector
	        for(it; it != visited.end(); ++it ){
	        	if(it->getPosition() == c.getPosition())
	        		result = true;
	        }		
	        return result;
	    }


		void setVisited(vector<Cell> visited){
			this->visited = visited;
		}
		//Might help for finding list spaces to go?
		vector<Cell> getVisited(){	
			return visited;
		}

		void setControlRoomFound(bool t){
			isControlRoomFound = t;
		}
		
		bool getControlRoomFound(){
		    return isControlRoomFound;
		}
		
		void addCell(Cell cell){
			if(cell.getVisited()){
				visited.push_back(cell);
			}
			if(cell.getType() == 'K'){
			    currentPosition = cell;
			}
			map.push_back(cell);
		}

		void setSizeX(int x){
			sizeX = x;
		}

		void setSizeY(int y){
			sizeY = y;
		}

        int getCurrentPosition(){
            return currentPosition.getPosition();
        }
        
        Cell getCurrentCell(){
            return currentPosition;
        }
        
        
		void printMap(){

	        vector<Cell>::iterator it = map.begin();
	        //try to print from vector
	        int i = 0;
	        for(it; it != map.end(); ++it ){
	            cerr << it->getType();
	            i++;
	            if(i == sizeX){
	                cerr << endl;
	                i = 0;
	            }
	        }   
		}

		void setStartingCell(Cell c){
			startPosition = c;
		}

		void setControlRoomCell(Cell c){
			controlRoom = c;
		}

		Cell getControlRoom(){
			return controlRoom;
		}

		Cell getStartCell(){
			return startPosition;
		}

		bool getControlRoomVisible(){
			return isControlRoomVisible;
		}

		void setControlRoomVisible(bool b){
			isControlRoomVisible = b;
		}

	private:
	
		Cell getCellAtPosition(int position){
			return map.at(position);
		}

		Cell controlRoom;
	    Cell currentPosition;
	    Cell startPosition;
		vector<Cell> map;
		vector<Cell> visited;
		bool isControlRoomVisible;
		bool isControlRoomFound;
		int sizeX; //columns 
		int sizeY; //rows
};

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    bool foundControlRoom = false;
    int R; // number of rows.
    int C; // number of columns.
    int A; // number of rounds between the time the alarm countdown is activated and the time the alarm goes off.
    // map<int, map<int, bool> > visited;
    cin >> R >> C >> A; cin.ignore();
    // string maps[R][C]; // Must be rows before columns
    // game loop
    vector<Cell> visited;
    while (1) {
        Map map;
        map.setSizeX(C);
        map.setSizeY(R);
        int KR; // row where Kirk is located.
        int KC; // column where Kirk is located.
        cin >> KR >> KC; cin.ignore();
        cerr << "R: " << R << " C: " << C << " A: " << A << endl;
        int position = 0;
        for (int i = 0; i < R; i++) {
            string ROW; // C of the characters in '#.TC?' (i.e. one line of the ASCII maze).
            cin >> ROW; cin.ignore();
        
            
            for(int c = 0; c<C; c++){

                // string element(ROW.at(c), 1);
	        	try{
	                Cell cell;
	                char element = ROW.at(c);
	                if( i == KR && c == KC){
	                    if(element == 'C'){
	                        foundControlRoom = true;
	                    }
	                    if(element == 'T'){
	                    	cell = Cell('T', position, true, c, i);
	                    	map.setStartingCell(cell);
	                    }
	                    // maps[i][c] = 'K';
	                    // visited[i][c] = true;
	                    cell = Cell('K', position, true, c, i);
	                    visited.push_back(cell); // Need to have visited outside of map because map is being reset everytime
	                    map.setVisited(visited);
	                }else{
	                	if(element == 'C'){
	                		map.setControlRoomVisible(true);
	                        cell = Cell('C', position, false, c, i);
	                        map.setControlRoomCell(cell);
	                	}
	                    // maps[i][c] = element;
	                    cell = Cell(element, position, false, c, i);
	                }
	                map.addCell(cell);
	            }
	            catch(std::exception& e){
	            	cerr << "SOMETHING WENT REALLY WRONG" << endl;
	            }
	            position ++;
            }
        }
        
        map.printMap();
        
        cerr << map.getCurrentPosition() <<endl;
        vector<Cell> neighbors = map.getNeighbors();
        vector<Cell>::iterator it = neighbors.begin();
	        //try to print from vector
	        for(it; it != neighbors.end(); ++it ){
	            cerr << it->getType() << " X: " << it->getPositionColumn() << " Y: " << it->getPostionRow()<<endl;

	        }
	        
	    if(foundControlRoom){
			//I wanna make a method to go through the cells and compare and contrast values and check what is the best way to go. We could weigh the individual 
	    	//Aspects against eachother such as distance to see which one would benefit us more
	    	Cell start = map.getStartCell();
	    	Cell current = map.getCurrentCell();
	    	cerr << "current " << current.getPositionColumn() << endl;
			int diffColumn = start.getPositionColumn() - current.getPositionColumn();
			int diffRow = start.getPostionRow() - current.getPostionRow();
            
            cerr << "DiffColumn: " << diffColumn << " diffRow " << diffRow <<endl;
			if (diffRow > diffColumn)
			{
				if(diffRow <= 0 && map.getNeighbors()[0].getExplorable()){
					cout << "LEFT" << endl;
					cerr << "LEFT: " << endl;
				} else if(diffRow > 0 && map.getNeighbors()[1].getExplorable()){
					cout << "RIGHT" << endl;
					cerr << "RIGHT: " << endl;
				}
			}

			if (diffRow < diffColumn)
			{
				if(diffColumn <= 0 && map.getNeighbors()[3].getType() == '.'){
					cout << "UP" << endl;
				} else if(diffColumn > 0 && map.getNeighbors()[2].getType() == '.'){
					cout << "DOWN" << endl;
				}
			}   		
		}else{
   			if(map.getControlRoomVisible()){
   			    cerr << "CONTROL ROOM SEEN " << endl;
	   					//This will do it if the control room is visible
		    	Cell controlRoom = map.getControlRoom();
		    	Cell current = map.getCurrentCell();
		    	cerr << "current Column " << current.getPositionColumn() << endl;
		    	cerr << "current Row " << current.getPostionRow() << endl;
		    	cerr << "control Row " << controlRoom.getPostionRow() << endl;
				int diffColumn = controlRoom.getPositionColumn() - current.getPositionColumn();
				int diffRow = controlRoom.getPostionRow() - current.getPostionRow();
	            
	            cerr << "DiffColumn: " << diffColumn << " diffRow " << diffRow <<endl;
				if (diffRow < diffColumn)
				{
				    cerr << "If 1" << endl;
					if(diffColumn <= 0 && map.getNeighbors()[0].getExplorable()){
						cout << "LEFT" << endl;
						cerr << "LEFT: " << endl;
					} else if(diffColumn > 0 && map.getNeighbors()[1].getExplorable()){
						cout << "RIGHT" << endl;
						cerr << "RIGHT: " << endl;
					}
				}

				if (diffRow > diffColumn)
				{
				    cerr << "if 2 " << endl;
					if(diffRow <= 0 && map.getNeighbors()[3].getType() == '.'){
						cout << "UP" << endl;
					} else if(diffRow > 0 && map.getNeighbors()[2].getType() == '.'){
						cout << "DOWN" << endl;
					}
				}
   			}else{
   			    cerr << " CONTROL ROOM NOT SEEN" << endl;
   				bool UP = false;
   				bool DOWN = false;
   				bool LEFT = false;
   				bool RIGHT = false;
   				vector<Cell> neighbors = map.getNeighbors();
   				if(neighbors[0].getExplorable() && !map.compareToVisited(neighbors[0])){
   					LEFT = true;
   				}else if(neighbors[1].getExplorable() && !map.compareToVisited(neighbors[1])){
   					RIGHT = true;
   				}else if(neighbors[2].getExplorable() && !map.compareToVisited(neighbors[2])){
   					UP = true;
   				}else if(neighbors[3].getExplorable() && !map.compareToVisited(neighbors[3])){
   					DOWN = true;
   				}

   				if(LEFT){
   					cout << "LEFT" <<endl;
   				}else if(RIGHT){
   					cout << "RIGHT" <<endl;
   				}else if(UP){
   					cout << "UP" <<endl;
   				}else if(DOWN){
   					cout << "DOWN" <<endl;
   				}
   			}
   		}
   	}
}


