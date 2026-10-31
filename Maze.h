#ifndef Maze_h
#define Maze_h
#include "Tile.h"
#include <string>
class Maze{
    private:
    void setTile();
    public:
    Maze();
    Tile getTile();
    void setMaze(std::string);
};
#endif