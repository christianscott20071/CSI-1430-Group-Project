#ifndef Maze_h
#define Maze_h
#include "Tile.h"
#include <string>
using namespace std;
class Maze{

private:
    std::string line;
    static const int MAZE_SIZE = 100;
    int x, y;

    Tile mazeMat[MAZE_SIZE][MAZE_SIZE];
    int height = 0;
    int width = 0;
    int tileSize = 30;
    int startX = 0;
    int startY = 0;
    int endX = 0;
    int endY = 0;

    public:
    void setTile(Tile, int, int);
    int playerStartX();
    int playerStartY();
    int playerEndX();
    int playerEndY();
    void clearMazeMat();
    int getTileSize();
    int getHeight();
    int getWidth();
    Maze();
    Tile getTile(int, int);
    void setMaze(int);

};
#endif