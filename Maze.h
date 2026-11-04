#ifndef Maze_h
#define Maze_h
#include "Tile.h"
#include <string>
class Maze{

private:
    std::string line;
    static const int MAZE_SIZE = 100;
    int x, y;

    Tile mazeMat[MAZE_SIZE][MAZE_SIZE];
    int height = 0;
    int width = 0;
    int tileSize = 30;



    public:
    void setTile(Tile, int, int);
    int getTileSize();
    int getHeight();
    int getWidth();
    Maze();
    Tile getTile(int, int);
    void setMaze(std::string);
};
#endif