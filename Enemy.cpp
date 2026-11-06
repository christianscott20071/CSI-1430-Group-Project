#include "Enemy.h"

    Enemy::Enemy() : Entity(0, 0) {}

    Enemy::Enemy(int damage) : Entity(0, 0) {
        this->damage = damage;
    }
    void Enemy::changeState(int state){
        //0 for normal 1 for scared
        if(state == 0) isScared = false;
        if(state == 1) isScared = true;
    }
    int Enemy::getDamage(){
        return damage;
    }


