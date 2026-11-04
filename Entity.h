#ifndef Entity_h
#define Entity_h

class Entity{
    public:
    Entity(int x, int y);
    Entity();
    void startOver();
    int getX();
    int getY();
    void updatePosition(int, int);

private:
    int xPos, yPos;
    int startX, startY;

};
#endif