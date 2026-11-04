#include "Tile.h"

    Tile::Tile(bool isWall, bool hasDot, bool hasPowerup){
        this->isWall = isWall;
        this->hasDot = hasDot;
        this->hasPowerup = hasPowerup;
    }
    Tile::Tile(){
        isWall = true;
        hasDot = false;
        hasPowerup = false;
    }
    //We are going to return 0 for wall, 1 for dot, and 2 for powerup
    int Tile::getTileState(){
        int state = 0;
        if(hasDot) state = 1;
        if(hasPowerup) state = 2; 
        return state;
    }
    bool Tile::getIsWall() {
        return isWall;
    };

