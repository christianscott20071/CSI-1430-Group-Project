#include "Tile.h"

    enum TileType{
        PATH,
        WALL,
        ICE,
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
        if(type == ICE) state = 2;
        if(type == MUD) state = 3;
        if(type == TELEPORT) state = 4;
        if(type == START) state = 5;
        if(type == FINISH) state = 6;
        return state;
    }

