#include "Tile.h"
class Maze{
    private:
    int x, y;
    Tile mazeMat[50][50];
    public:
    Maze(){
        //Put maze here
        //Sample Maze
        mazeMat[0][0] = Tile(false, false, false);
    }

    Tile getTile(int xPos, int yPos){
        return mazeMat[xPos][yPos];
    } 
};