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
                    if(numTile == '5') mazeMat[width][height] = Tile(Tile::TELEPORT_1), tele1X = width, tele1Y = height;
                    if(numTile == '6') mazeMat[width][height] = Tile(Tile::TELEPORT_2), tele2X = width, tele2Y = height;
                    if(numTile == '7') mazeMat[width][height] = Tile(Tile::TELEPORT_3), tele3X = width, tele3Y = height;
                    if(numTile == '8') mazeMat[width][height] = Tile(Tile::TELEPORT_4), tele4X = width, tele4Y = height;
                    if(numTile == '9') mazeMat[width][height] = Tile(Tile::HIDDEN_LAVA);
                    if(numTile == '!') mazeMat[width][height] = Tile(Tile::HIDDEN_WALL);
                    if(numTile == 'K') mazeMat[width][height] = Tile(Tile::KEY), keyX = width, keyY = height;
                    if(numTile == 'D') mazeMat[width][height] = Tile(Tile::DOOR), doorX = width, doorY = height;
                    if(numTile == '@') mazeMat[width][height] = Tile(Tile::START), startX = width, startY = height;
                    if(numTile == '*') mazeMat[width][height] = Tile(Tile::FINISH), endX = width, endY = height;


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

int Maze::getTele1X() {return tele1X;}
int Maze::getTele1Y() {return tele1Y;}
int Maze::getTele2X() {return tele2X;}
int Maze::getTele2Y() {return tele2Y;}

int Maze::getTele3X() {return tele3X;}
int Maze::getTele3Y() {return tele3Y;}
int Maze::getTele4X() {return tele4X;}
int Maze::getTele4Y() {return tele4Y;}

int Maze::getKeyX() {return keyX;}
int Maze::getKeyY() {return keyY;}
int Maze::getDoorX() {return doorX;}
int Maze::getDoorY() {return doorY;}

void Maze::toLava(int x, int y) {
        mazeMat[x][y] = Tile(Tile::LAVA);
}
void Maze::toWall(int x, int y) {
        mazeMat[x][y] = Tile(Tile::WALL);
    }

