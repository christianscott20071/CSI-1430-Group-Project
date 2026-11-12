#pragma once
#include "Entity.h"
class Player : public Entity{
    private:
    int health;
    public:
    Player();
    Player(int, int);
    int getHealth();
    void damagePlayer(int);
};