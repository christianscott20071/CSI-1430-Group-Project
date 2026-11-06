#include "Tile.h"

    Tile::Tile(int type){
        this->type = type;
/*
 * 0 = wall
 * 1 = floor
 * 2 = lava
 * 3 = speed
 * 4 = mud
 *
 *
 * 
 * 8 = start
 * 9 = end
 */
    }
    Tile::Tile(){
        type = 0;

    }
    //We are going to return 0 for wall,
    int Tile::getTileType(){
        return type;
    }
    bool Tile::getIsWall() {
        if (type == 0) {
            return true;
        }
        else {
            return false;
        }
    };

