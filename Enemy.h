#ifndef Enemy_h
#define Enemy_h
#include "Entity.h"

class Enemy : public Entity{
    public:

    Enemy();
    Enemy(int);
    void changeState(int);
    int getDamage();
};
#endif