#ifndef Enemy_h
#define Enemy_h
#include "Entity.h"

class Enemy : public Entity{
private:

    bool isScared;
    int damage;

public:
    Enemy();
    Enemy(int damage);
    void changeState(int state);
    int getDamage();
};

#endif