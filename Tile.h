#ifndef Tile_h
#define Tile_h

#pragma once
class Tile{
    public:
    Tile();
    Tile(bool, bool, bool);
    bool getIsWall();
    int getTileState();

private:
    bool isWall;
    bool hasDot;
    bool hasPowerup;

};

#endif