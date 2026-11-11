#include "Entity.h";

class Player : public Entity{
    private:

    int health = 10;

    public:

    Player(){

    }
    Player(int x, int y){
        xPos = x;
        yPos = y;

    }
    int getHealth(){
        return health;
    }
    int damagePlayer(int dmg){
        health -= dmg;
    }
    
};