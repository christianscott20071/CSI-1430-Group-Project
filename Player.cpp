#include "Player.h"
    Player::Player(){

    }
    Player::Player(int x, int y){
        xPos = x;
        yPos = y;

    }
    int Player::getHealth(){
        return health;
    }
    void Player::damagePlayer(int dmg){
        health -= dmg;
    }
    