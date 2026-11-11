#include "Tile.h"
#include <fstream>
#include <string>
#include "Maze.h"
using namespace std;
#include <iostream>

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
        inFile.clear();

        if (inFile.is_open()) {
            while(getline(inFile, line)) {
                width = 0;
                // 0=path 1=wall 2=LAVA speed up 3=speed up 4=MUD 5=start 6=finish
                for(int i = 0; i < line.size(); i++) {
                    numTile = line[i];
                    if (numTile == ' ') {continue;}
                    if(numTile == '0') mazeMat[width][height] = Tile(Tile::PATH);
                    if(numTile == '1') mazeMat[width][height] = Tile(Tile::WALL);
                    if(numTile == '2') mazeMat[width][height] = Tile(Tile::LAVA);
                    if(numTile == '3') mazeMat[width][height] = Tile(Tile::SPEEDUP);
                    if(numTile == '4') mazeMat[width][height] = Tile(Tile::MUD);
                    if(numTile == '5') mazeMat[width][height] = Tile(Tile::TELEPORT);
                    if(numTile == '6') mazeMat[width][height] = Tile(Tile::START), startX = width, startY = height;
                    if(numTile == '7') mazeMat[width][height] = Tile(Tile::FINISH),  endX = width, endY = height;


                    width++;
                }
                height++;
            }
        }
        else {
            cout << "Could not open " << filename << endl;
        }
    }

int Maze::playerStartX() {return startX;}
int Maze::playerStartY() {return startY;}

int Maze::playerEndX() {return endX;}
int Maze::playerEndY() {return endY;}
