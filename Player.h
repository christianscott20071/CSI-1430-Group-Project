#pragma once
#include "Entity.h"
class Player : public Entity{
    private:
    Player();
    int getHealth();
    int damagePlayer(int);
};