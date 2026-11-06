#ifndef Tile_h
#define Tile_h

class Tile{
    
    public:
    enum TileType{
        PATH,
        WALL,
        LAVA,
        SPEEDUP,
        MUD,
        TELEPORT,
        START,
        FINISH
    };
    Tile();
    Tile(TileType);
    int getTileState();
    bool getIsWall();
    private:
    TileType type;
};

#endif