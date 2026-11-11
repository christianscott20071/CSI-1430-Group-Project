#pragma once
#include "Entity.h"
class Player : public Entity{
    public:
    Player();
    Player(int, int);
    int getHealth();
    int damagePlayer(int);
};