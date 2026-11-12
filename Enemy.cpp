#include "Enemy.h"
    char direction;
    Enemy::Enemy() : Entity(0, 0) {}

    Enemy::Enemy(int damage) : Entity(0, 0) {
        this->damage = damage;
    }
    Enemy::Enemy(int x, int y){
        xPos = x;
        yPos = y;
        direction = '0'; //placeholder for inital dir, we will use n e s w
    }
    void Enemy::changeState(int state){
        //0 for normal 1 for scared
        if(state == 0) isScared = false;
        if(state == 1) isScared = true;
    }
    int Enemy::getDamage(){
        return damage;
    }
    void Enemy::setDirection(char dir){
        direction = dir;
    }
    char Enemy::getDirection(){
        return direction;
    }


