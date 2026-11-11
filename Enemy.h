#ifndef Enemy_h
#define Enemy_h
#include "Entity.h"

class Enemy : public Entity{
private:

    bool isScared;
    int damage;
    char direction;
public:
    Enemy();
    Enemy(int);
    Enemy(int, int);
    void changeState(int state);
    int getDamage();
    char getDirection();
};

#endif