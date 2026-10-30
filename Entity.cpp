class Entity{
    private:
    int xPos, yPos;
    int startX, startY;

    public:

    Entity(int x, int y){
        xPos = x;
        yPos = y;
    }
    Entity(){};
    int getX(){
        return xPos;
    }
    int getY(){
        return yPos;
    }
};
