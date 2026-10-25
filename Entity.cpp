class Entity{
    private:
    int xPos, yPos;
    int startX, startY;

    public:

    Entity(int x, int y){
        xPos = x;
        yPos = y;
    }
    int getX(){
        return xPos;
    }
    int getY(){
        return yPos;
    }
};
