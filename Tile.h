#ifndef Tile_h
#define Tile_h

class Tile{
    private:
    enum TileType{};
    TileType type;
    public:
    Tile();
    Tile(TileType);
    int getTileState();
};

#endif