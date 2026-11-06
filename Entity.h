#ifndef Entity_h
#define Entity_h

class Entity{
    public:
    Entity(int, int);
    void startOver();
    int getX();
    int getY();
    void updatePosition(int, int);
    void updateStart(int, int);


private:
    int xPos;
    int yPos;
    int startX;
    int startY;

};
#endif