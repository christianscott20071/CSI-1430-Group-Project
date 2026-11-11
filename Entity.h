#ifndef Entity_h
#define Entity_h

class Entity{
    public:
    Entity();
    Entity(int, int);
    void startOver();
    int getX();
    int getY();
    void updatePosition(int, int);
    void updateStart(int, int);

protected:
    int xPos;
    int yPos;
    int startX;
    int startY;

};
#endif