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
        TELEPORT_1,
        TELEPORT_2,
        TELEPORT_3,
        TELEPORT_4,
        HIDDEN_LAVA,
        HIDDEN_WALL,
        KEY,
        DOOR,
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