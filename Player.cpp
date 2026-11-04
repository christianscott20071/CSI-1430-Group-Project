#include "Entity.h";

class Player : public Entity{
    private:

    int health = 10;

    public:

    Player();
    int getHealth(){
        return health;
    }
    int damagePlayer(int dmg){
        health -= dmg;
    }
    
};