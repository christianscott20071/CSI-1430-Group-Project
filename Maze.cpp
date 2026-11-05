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
    }

    Tile Maze::getTile(int xPos, int yPos){
        return mazeMat[xPos][yPos];
    }
    void Maze::setMaze(std::string filename){
        char numTile;
        height = 0;
        std::string line;
        std::ifstream inFile(filename);

        if (inFile.is_open()) {
            while(getline(inFile, line)) {
                width = 0;
                // 0=path 1=wall 2=speed up 3=slow down 4=teleport 5=start 6=finish
                for(int i = 0; i < line.size(); i++) {
                    numTile = line[i];
                    if(numTile == '0') mazeMat[width][height] = Tile(Tile::PATH);
                    if(numTile == '1') mazeMat[width][height] = Tile(Tile::WALL);
                    if(numTile == '2') mazeMat[width][height] = Tile(Tile::ICE);
                    if(numTile == '3') mazeMat[width][height] = Tile(Tile::MUD);
                    if(numTile == '4') mazeMat[width][height] = Tile(Tile::TELEPORT);
                    if(numTile == '5') mazeMat[width][height] = Tile(Tile::START);
                    if(numTile == '6') mazeMat[width][height] = Tile(Tile::FINISH);
                    width++;
                }
                height++;
            }
        }
    }
