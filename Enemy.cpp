
#include "Entity.h";

class Enemy : public Entity{
    private:

    bool isScared;
    int damage;

    public:

    Enemy();
    Enemy(int damage){
        this->damage;
    };
    void changeState(int state){
        //0 for normal 1 for scared
        if(state == 0) isScared = false;
        if(state == 1) isScared = true;
    }
    int getDamage(){
        return damage;
    }
};