
#include <cmath>
#include <climits>
#include "SDL_Plotter.h"
#include "Enemy.h"
#include "Player.h"
#include "Maze.h"
#include "Tile.h"
#include <vector>
using namespace std;

int main (int argc, char ** argv) {
    int level = 1;
    Maze maze;
    maze.setMaze(level);
    SDL_Plotter plot(maze.getHeight() * maze.getTileSize(), maze.getWidth() * maze.getTileSize(), false);
    Player player(maze.playerStartX(), maze.playerStartY());
    Enemy enemy(maze.playerStartX(), maze.playerStartY()); //Enemy start pos will be at the start of the maze, enemy will spawn in like a second or two after player. 
    bool isLava = false;
    bool level_complete = false;
    char key;
    int newX = 0;
    int newY = 0;
    int changeX = 0;
    int changeY = 0;
    bool isHiddenLava = false;
    bool changeToLava = false;
    bool hiddenTile = false;
    bool changeTile = false;
    bool skip = false;
    bool hasKey = false;
    bool isLocked = true;

    cout << "Maze size:" << maze.getHeight() * maze.getTileSize(), maze.getWidth() * maze.getTileSize();

    while (!plot.getQuit()) {
        if (plot.kbhit()) {

            key = plot.getKey();
            newX = player.getX();
            newY = player.getY();
            int dy = 0;
            int dx = 0;

            switch (key) {
                case 'w':
                    dy = -1;
                    break;
                case 's':
                    dy = 1;
                    break;
                case 'a':
                    dx = -1;
                    break;
                case 'd':
                    dx = 1;
                    break;
            }

            newY += dy;
            newX += dx;
            isLava = false;
            isHiddenLava = false;
            level_complete = false;

            if (!maze.getTile(newX, newY).getIsWall()) {
                switch (maze.getTile(newX, newY).getTileState()) {
                    case 2:
                        //LAVA
                        isLava = true;
                        break;
                    case 3:
                        //SPEED
                        if (maze.getTile(newX + dx, newY + dy).getTileState() == 0) {
                            newY += dy;
                            newX += dx;
                        break;
                    case 4:
                        //MUD
                        skip = !skip;
                        if (skip) {
                            newY += -1 * dy;
                            newX += -1 * dx;
                        }
                        break;
                    case 5:
                        //TELEPORT_1
                        newX = maze.getTele2X();
                        newY = maze.getTele2Y();
                        break;
                    case 6:
                        //TELEPORT_2
                        newX = maze.getTele1X();
                        newY = maze.getTele1Y();
                        break;
                    case 7:
                        //TELEPORT_3
                        newX = maze.getTele4X();
                        newY = maze.getTele4Y();
                        break;
                    case 8:
                        //TELEPORT_4
                        newX = maze.getTele3X();
                        newY = maze.getTele3Y();
                        break;
                    case 9:
                        //HIDDEN_LAVA
                        hiddenTile = true;
                        isHiddenLava = true;
                        break;
                    case 10:
                        //HIDDEN_WALL
                        hiddenTile = true;
                        isHiddenLava = false;
                        break;
                    case 11:
                        hasKey = true;
                        maze.setTile(Tile(Tile::PATH), newX, newY);
                        maze.setTile(Tile(Tile::PATH), maze.getDoorX(), maze.getDoorY());
                        //drawMaze.hasKey() = true;
                        // This wll draw some visual which tells you that you've picked up the key and unlocked the door.
                        // It will be drawn on top of the screen at the end of the normal draw sequence.
                        break;

                    case 14:
                        level_complete = true;
                        break;

                    default:
                        break;
                }

                if (isLava) {
                    player.startOver();
                }
                else {
                    player.updatePosition(newX, newY);
                }

                if (changeTile && (changeX != player.getX() || changeY != player.getY())) {
                    if (changeToLava) {
                        maze.setTile(Tile(Tile::LAVA), changeX, changeY);
                    }
                    else if (!changeToLava) {
                        maze.setTile(Tile(Tile::WALL), changeX, changeY);
                    }
                    changeTile = false;
                    changeToLava = false;
                }

                if (hiddenTile == true) {
                    changeX = player.getX();
                    changeY = player.getY();
                    changeTile = true;
                    if (isHiddenLava) changeToLava = true; else changeToLava = false;
                }
                hiddenTile = false;
                isHiddenLava = false;


                if (level_complete) {
                    // drawVictoryScreen(plot, level);
                    level++;
                    changeTile = false;
                    skip = false;

                    if (level > 3) {
                        // drawGameBeatScreen(plot);
                        plot.setQuit(true);
                    }

                    else {
                        maze.setMaze(level);
                        player.updateStart(maze.playerStartX(), maze.playerStartY());
                        player.updatePosition(maze.playerStartX(), maze.playerStartY());
                    }
                }
            }
        }

        plot.clear();

        // drawMaze(plot, maze);
        // drawPlayer(plot, player);

        plot.update();

        plot.Sleep(30);

    }

    return 0;
}



struct MoveOption{
    int x;
    int y;
};

void updateEnemy(Enemy& enemy, Player player, Maze maze){
    int distance = INT_MAX;
    MoveOption bestOption;
    vector<MoveOption> options;

    //check north
    if((enemy.getY()+1 >=0 && enemy.getY() < maze.getHeight())
    && maze.getTile(enemy.getX(), enemy.getY()+1).getTileState()!=Tile::WALL
     && enemy.getDirection()!='s'){
        options.push_back({enemy.getX(), enemy.getY()+1});
    }
    //check east
    if((enemy.getX()+1 >=0 && enemy.getX() < maze.getWidth())
     && maze.getTile(enemy.getX()+1, enemy.getY()).getTileState()!=Tile::WALL
      && enemy.getDirection()!= 'w'){
        options.push_back({enemy.getX()+1, enemy.getY()});
    }
    //check south
    if((enemy.getY()+1 >=0 && enemy.getY() < maze.getHeight())
     && maze.getTile(enemy.getX(), enemy.getY()-1).getTileState()!=Tile::WALL
      && enemy.getDirection()!='n'){
        options.push_back({enemy.getX(), enemy.getY()-1});
    }
    //check west
    if((enemy.getX()+1 >=0 && enemy.getX() < maze.getWidth())
     && maze.getTile(enemy.getX()-1, enemy.getY()).getTileState()!=Tile::WALL
      && enemy.getDirection()!= 'e'){
        options.push_back({enemy.getX()-1, enemy.getY()});
    }

    //so now we need to go through our valid tiles and whichever one has the shortest distance to the player, we save.
    for(int i = 0; i < options.size(); i++){
        if(abs((options[i].x - player.getX())) + abs(options[i].y-player.getY()) < distance){
            bestOption = options[i];
            distance = abs((enemy.getX() - player.getX())) + abs(enemy.getY()-player.getY());
        }
    }
    //now we update position
    enemy.updatePosition(bestOption.x, bestOption.y);
}

