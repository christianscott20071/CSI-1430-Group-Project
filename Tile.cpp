#include "Tile.h"


    Tile::Tile(){}
    Tile::Tile(TileType type){
        this->type = type;
    }

    int Tile::getTileState(){
        int state = 0;
        if(type == WALL) state = 1;
        if(type == LAVA) state = 2;
        if(type == SPEEDUP) state = 3;
        if(type == MUD) state = 4;
        if(type == TELEPORT_1) state = 5;
        if(type == TELEPORT_2) state = 6;
        if(type == TELEPORT_3) state = 7;
        if(type == TELEPORT_4) state = 8;
        if(type == HIDDEN_LAVA) state = 9;
        if(type == HIDDEN_WALL) state = 10;
        if (type == KEY) state = 11;
        if (type == DOOR) state = 12;
        if(type == START) state = 13;
        if(type == FINISH) state = 14;
        return state;
    }

    bool Tile::getIsWall() {
        if (type == WALL || type == DOOR) {
            return true;
        }
        else {
            return false;
        }
    }

