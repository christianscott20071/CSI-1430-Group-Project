#include "Entity.h"

    Entity::Entity(){
        
    }
    Entity::Entity(int x, int y) {
        xPos = x;
        yPos = y;
        startX = x;
        startY = y;
    }
    void Entity::updateStart(int newStartX, int newStartY) {
        startX = newStartX;
        startY = newStartY;
    }

    int Entity::getX(){
        return xPos;
    }
    int Entity::getY(){
        return yPos;
    }
    void Entity::updatePosition(int x, int y) {
        xPos = x;
        yPos = y;
    }

    void Entity::startOver() {
        xPos = startX;
        yPos = startY;
}






