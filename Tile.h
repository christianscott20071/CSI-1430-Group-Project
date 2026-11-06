#ifndef Tile_h
#define Tile_h

#pragma once
class Tile{
    public:
    Tile();
    Tile(int);
    bool getIsWall();
    int getTileType();

private:
    int type;



};

#endif