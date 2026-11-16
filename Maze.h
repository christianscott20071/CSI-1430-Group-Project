#ifndef Maze_h
#define Maze_h
#include "Tile.h"
#include <string>
using namespace std;
class Maze{

private:
    std::string line;
    static const int MAZE_SIZE = 25;
    int x, y;

    Tile mazeMat[MAZE_SIZE][MAZE_SIZE];
    int height = 25;
    int width = 25;
    int tileSize = 30;
    int startX = 1;
    int startY = 1;
    int endX = 0;
    int endY = 0;
    int tele1X = 0;
    int tele1Y = 0;
    int tele2X = 0;
    int tele2Y = 0;
    int tele3X = 0;
    int tele3Y = 0;
    int tele4X = 0;
    int tele4Y = 0;
    int keyX = 0;
    int keyY = 0;
    int doorX = 0;
    int doorY = 0;


    public:
    void setTile(Tile, int, int);
    int playerStartX();
    int playerStartY();
    int playerEndX();
    int playerEndY();
    int getTele1X();
    int getTele1Y();
    int getTele2X();
    int getTele2Y();
    int getTele3X();
    int getTele3Y();
    int getTele4X();
    int getTele4Y();
    int getKeyX();
    int getKeyY();
    int getDoorX();
    int getDoorY();
    void clearMazeMat();
    int getTileSize();
    int getHeight();
    int getWidth();
    Maze();
    Tile getTile(int, int);
    void setMaze(int);
    void toLava(int, int);
    void toWall(int, int);

};
#endif