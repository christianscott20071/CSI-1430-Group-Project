#include "Tile.h"
#include <fstream>
#include <string>
class Maze{
    private:
    static const int MAZE_SIZE = 50;
    int x, y;
    void setTile(Tile tile, int x, int y){
        mazeMat[x][y] = tile;
    }
    Tile mazeMat[MAZE_SIZE][MAZE_SIZE];
    public:
    Maze(){
        //we will construct a maze obj and read a file into it.
        //Sample Maze
        mazeMat[0][0] = Tile(false, false, false);
    }

    Tile getTile(int xPos, int yPos){
        return mazeMat[xPos][yPos];
    } 
    void setMaze(std::string filename){
        char numTile;
        std::ifstream inFile(filename);
        for(int i = 0; i < MAZE_SIZE; i++){
            for(int j = 0; j < MAZE_SIZE; j++){
                inFile >> numTile;
                //read maze
                //0 is for wall, 1 is for dot, 2 is for powerup
                if(numTile == '0') mazeMat[i][j] = Tile(true, false, false);
                if(numTile == '1') mazeMat[i][j] = Tile(false, true, false);
                if(numTile == '2') mazeMat[i][j] = Tile(false, false, true);
            }
        }
    }
};