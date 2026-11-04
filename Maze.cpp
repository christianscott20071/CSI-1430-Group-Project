#include "Tile.h"
#include <fstream>
#include <string>
#include "Maze.h"

    void Maze::setTile(Tile tile, int x, int y){
        mazeMat[x][y] = tile;
}
    int Maze::getTileSize() {
        return tileSize;
    }
    int Maze::getHeight() {
        return height;
    }
    int Maze::getWidth() {
        return width;
    }

    Maze::Maze(){
        //we will construct a maze obj and read a file into it.
        //Sample Maze
        mazeMat[0][0] = Tile(false, false, false);
    }

    Tile Maze::getTile(int xPos, int yPos){
        return mazeMat[xPos][yPos];
    }
    void Maze::setMaze(std::string filename){
        char numTile;
        height = 0;
        std::ifstream inFile(filename);

        if (inFile.is_open()) {
            while(getline(inFile, line)) {
                width = 0;

                for(int i = 0; i < line.size(); i++) {
                    numTile = line[i];
                    if(numTile == '0') mazeMat[width][height] = Tile(true, false, false);
                    if(numTile == '1') mazeMat[width][height] = Tile(false, true, false);
                    if(numTile == '2') mazeMat[width][height] = Tile(false, false, true);

                    width++;
                }
                height++;
            }
        }
    }
