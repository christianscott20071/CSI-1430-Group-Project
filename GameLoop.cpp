

#include <cmath>
#include "SDL_Plotter.h"
#include "Entity.h"
#include "Maze.h"
#include "Tile.h"
using namespace std;

int main (int argc, char ** argv) {
    int level = 1;
    Maze maze;
    maze.setMaze(level);
    SDL_Plotter plot(maze.getHeight() * maze.getTileSize(), maze.getWidth() * maze.getTileSize(), false);
    Entity player(maze.playerStartX(), maze.playerStartY());


    char key;
    int newX = 0;
    int newY = 0;
    bool skip = false;

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
            bool islava = false;
            bool level_complete = false;



            if (!maze.getTile(newX, newY).getIsWall()) {
                switch (maze.getTile(newX, newY).getTileType()) {
                    case 2:
                        //LAVA
                        islava = true;
                        break;
                    case 3:
                        //SPEED
                        newY += dy;
                        newX += dx;
                        if (maze.getTile(newX, newY).getIsWall()) {
                            newY -= dy;
                            newX -= dx;
                        }
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
                        break;
                    case 6:
                        break;
                    case 9:
                        level_complete = true;

                        break;

                    default:
                        break;
                }

                if (islava) {
                    player.startOver();
                }
                else {
                    player.updatePosition(newX, newY);
                }


                if (level_complete) {
                    // drawVictoryScreen(plot, level);
                    level++;

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