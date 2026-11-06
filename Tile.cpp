#include "Tile.h"

    enum TileType{
        PATH,
        WALL,
        LAVA,
        SPEEDUP,
        MUD,
        TELEPORT,
        START,
        FINISH
    };
    TileType type;
    Tile::Tile(){
        
    }
    Tile::Tile(TileType type){
        this->type = type;
    }
    //We are going to return 
    // 0=path 1=wall 2=speed up 3=slow down 4=teleport 5=start 6=finish
    int Tile::getTileState(){
        int state = 0;
        if(type == WALL) state = 1;
        if(type == LAVA) state = 2;
        if(type == SPEEDUP) state = 3;
        if(type == MUD) state = 4;
        if(type == TELEPORT) state = 5;
        if(type == START) state = 6;
        if(type == FINISH) state = 7;
        return state;
    }

    bool Tile::getIsWall() {
        if (type == WALL) {
            return true;
        }
        else {
            return false;
        }
    }

