#include <cmath>
#include <climits>
#include <fstream>
#include "SDL_Plotter.h"
#include "Enemy.h"
#include "Player.h"
#include "Maze.h"
#include "Tile.h"
using namespace std;


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
    //now we set direction
    if(bestOption.x > enemy.getX()) enemy.setDirection('e');
    if(bestOption.x < enemy.getX()) enemy.setDirection('w');
    if(bestOption.y > enemy.getY()) enemy.setDirection('n');
    if(bestOption.y < enemy.getY()) enemy.setDirection('s');

    //aaaanndddd update position
    enemy.updatePosition(bestOption.x, bestOption.y);

   
    
}

//we need a ppm file
void drawImage(SDL_Plotter& p, string filename, int startX, int startY){
    string filepath = "images/" + filename;
    ifstream inFile;
    string line;
    int wid, height;
    int currX = startX;
    int currY = startY;
    int r,g,b;
    int maxVal;
    inFile.open(filepath);
    if(!inFile.is_open()){
        cout << "File reading error" << filename;
        return;
    }
    getline(inFile, line);
    inFile >> wid >> height;
    inFile >> maxVal;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < wid; j++){
            inFile >> r >> g >> b;
            p.plotPixel(currX, currY, r, g, b);
            currX++;
        }
        currY++;
        currX = startX;
    }
}







int main (int argc, char ** argv) {
    bool onTitleScreen = true;
    int level = 1;
    Maze maze;
    maze.setMaze(level);
    SDL_Plotter plot(maze.getHeight() * maze.getTileSize(), maze.getWidth() * maze.getTileSize(), false);
    Player player(maze.playerStartX(), maze.playerStartY());
    Enemy enemy(maze.playerStartX(), maze.playerStartY()); //Enemy start pos will be at the start of the maze, enemy will spawn in like a second or two after player. 
    bool islava = false;
    bool level_complete = false;
    char key;
    int newX = 0;
    int newY = 0;
    bool skip = false;

    cout << "Maze size:" << maze.getHeight() * maze.getTileSize(), maze.getWidth() * maze.getTileSize();

    //Title screen
    
        drawImage(plot, "candyTitleS.PPM", 0,0);
        plot.update();

        while(!plot.getQuit() && onTitleScreen){
            if(plot.kbhit()) {
                if(key = SDLK_RETURN) onTitleScreen = false;
            }
            plot.Sleep(30);
        }

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
            islava = false;
            level_complete = false;

            if (!maze.getTile(newX, newY).getIsWall()) {
                switch (maze.getTile(newX, newY).getTileState()) {
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
                        //TELEPORT
                        break;
                    case 7:
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
        //updateEnemy(enemy, player, maze);
        plot.update();

        plot.Sleep(30);

    }

    return 0;
}
