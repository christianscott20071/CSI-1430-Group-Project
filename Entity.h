#ifndef Entity_h
#define Entity_h

class Entity{
    public:
    Entity(int x, int y);
    Entity();
    int getX();
    int getY();
    void updatePosition(int, int);
};
#endif