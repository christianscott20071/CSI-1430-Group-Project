
#include "SDL_Plotter.h"
#include "Entity.h"
#include "Maze.h"
#include "Tile.h"

int main (int argc, char ** argv) {
    Maze maze;
    maze.setMaze("maze.txt");
    SDL_Plotter plot(maze.getHeight() * maze.getTileSize(), maze.getWidth() * maze.getTileSize(), false);
    Entity player(10, 10);

    char key;
    int newX = 0;
    int newY = 0;

    while (!plot.getQuit()) {
        if (plot.kbhit()) {
            key = plot.getKey();

            newX = player.getX();
            newY = player.getY();

            switch (key) {
                case 'w':
                    newY--;
                    break;
                case 's':
                    newY++;
                    break;
                case 'a':
                    newX--;
                    break;
                case 'd':
                    newX++;
                    break;
                }

                if (newX >= 0 && newY >= 0 &&
                    newX < maze.getWidth() && newY < maze.getHeight() &&
                        !maze.getTile(newX, newY).getIsWall()) {

                    player.updatePosition(newX, newY);
                }
            }

        plot.clear();


        // drawMaze(plot, maze);
        // drawPlayer(plot, player);

        plot.update();

        plot.Sleep(5);
    }
}