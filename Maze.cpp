#include "Tile.h"
#include <fstream>
#include <string>
#include "Maze.h"

    void Maze::setTile(Tile tile, int x, int y){
        mazeMat[x][y] = tile;
}
    void Maze::clearMazeMat() {
        for (int x = 0; x < MAZE_SIZE; x++) {
            for (int y = 0; y < MAZE_SIZE; y++) {
                mazeMat[x][y] = Tile();
            }
        }
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
    }

    Tile Maze::getTile(int xPos, int yPos){
        return mazeMat[xPos][yPos];
    }

    void Maze::setMaze(int level){
        char numTile;
        height = 0;
        string filename;
        clearMazeMat();

        if (level == 1) {
            filename = "maze1.txt";
        }
        if (level == 2) {
            filename = "maze2.txt";
        }
        if (level == 3) {
            filename = "maze3.txt";
        }

        ifstream inFile(filename);

        if (inFile.is_open()) {
            while(getline(inFile, line)) {
                width = 0;

                for(int i = 0; i < line.size(); i++) {
                    numTile = line[i];
                    mazeMat[width][height] = Tile(numTile - '0');
                    if(numTile == '8') startX = width, startY = height;
                    if(numTile == '9') endX = width, endY = height;
                    width++;
                }
                height++;
            }
        }
    }

int Maze::playerStartX() {return startX;}
int Maze::playerStartY() {return startY;}
int Maze::playerEndX() {return endX;}
int Maze::playerEndY() {return endY;}
