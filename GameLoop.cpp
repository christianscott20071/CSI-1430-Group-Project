
#include <cmath>
#include <climits>
#include <fstream>
#include "SDL_Plotter.h"
#include "Enemy.h"
#include "Player.h"
#include "Maze.h"
#include "Tile.h"
#include <cstdlib>
#include <vector>
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
    if((enemy.getY()-1 >=0 && enemy.getY() < maze.getHeight()) && (enemy.getX()-1 >=0 && enemy.getX() < maze.getWidth())
    && maze.getTile(enemy.getX(), enemy.getY()-1).getTileState()!=Tile::WALL
     && enemy.getDirection()!='s'){
        options.push_back({enemy.getX(), enemy.getY()-1});
    }
    //check east
    if((enemy.getX()+1 >=0 && enemy.getX() < maze.getWidth()) && (enemy.getY()-1 >=0 && enemy.getY() < maze.getHeight())
     && maze.getTile(enemy.getX()+1, enemy.getY()).getTileState()!=Tile::WALL
      && enemy.getDirection()!= 'w'){
        options.push_back({enemy.getX()+1, enemy.getY()});
    }
    //check south
    if(enemy.getY()+1 >=0 && enemy.getY() < maze.getHeight() && (enemy.getX()-1 >=0 && enemy.getX() < maze.getWidth())
     && maze.getTile(enemy.getX(), enemy.getY()+1).getTileState()!=Tile::WALL
      && enemy.getDirection()!='n'){
        options.push_back({enemy.getX(), enemy.getY()+1});
    }
    //check west
    if((enemy.getX()-1 >=0 && enemy.getX() < maze.getWidth()) && (enemy.getY()-1 >=0 && enemy.getY() < maze.getHeight())
     && maze.getTile(enemy.getX()-1, enemy.getY()).getTileState()!=Tile::WALL
      && enemy.getDirection()!= 'e'){
        options.push_back({enemy.getX()-1, enemy.getY()});
    }

    //so now we need to go through our valid tiles and whichever one has the shortest distance to the player, we save.
    /*
    for(int i = 0; i < options.size(); i++){
        if(abs((options[i].x - player.getX())) + abs(options[i].y-player.getY()) < distance){
            bestOption = options[i];
            distance = abs((options[i].x - player.getX())) + abs(options[i].y-player.getY());
        }
    }
        */
    //now we set direction


    //check if it is stuck
    if(options.empty()){
        //leave out direction restricting.
            if((enemy.getY()-1 >=0 && enemy.getY() < maze.getHeight())
        && maze.getTile(enemy.getX(), enemy.getY()-1).getTileState()!=Tile::WALL){
            options.push_back({enemy.getX(), enemy.getY()-1});
        }
        //check east
        if((enemy.getX()+1 >=0 && enemy.getX() < maze.getWidth())
        && maze.getTile(enemy.getX()+1, enemy.getY()).getTileState()!=Tile::WALL){
            options.push_back({enemy.getX()+1, enemy.getY()});
        }
        //check south
        if((enemy.getY()+1 >=0 && enemy.getY() < maze.getHeight())
        && maze.getTile(enemy.getX(), enemy.getY()+1).getTileState()!=Tile::WALL){
            options.push_back({enemy.getX(), enemy.getY()+1});
        }
        //check west
        if((enemy.getX()-1 >=0 && enemy.getX() < maze.getWidth())
        && maze.getTile(enemy.getX()-1, enemy.getY()).getTileState()!=Tile::WALL){
            options.push_back({enemy.getX()-1, enemy.getY()});
        }
    }

    //sometimes the enemy gets stuck, so sometimes, we will have it pick a random tile so it can get unstuck.

    if(rand() %100 < 15){
        bestOption = options[rand() %options.size()];
    }else{
        if(!options.empty()){
        for(int i = 0; i < options.size(); i++){
        if(abs((options[i].x - player.getX())) + abs(options[i].y-player.getY()) < distance){
            bestOption = options[i];
            distance = abs((options[i].x - player.getX())) + abs(options[i].y-player.getY());
        }
    }
    }
    }

    if(bestOption.x > enemy.getX()) enemy.setDirection('e');
    if(bestOption.x < enemy.getX()) enemy.setDirection('w');
    if(bestOption.y < enemy.getY()) enemy.setDirection('n');
    if(bestOption.y > enemy.getY()) enemy.setDirection('s');

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

void drawMaze(SDL_Plotter& p, Maze m){
    int xTracker = 0, yTracker = 0;
    for(int i = 0; i < m.getHeight(); i++){
        for (int j = 0; j < m.getWidth(); j++){
            if(m.getTile(j,i).getTileState() == 1){
                drawImage(p, "brickWall.ppm", xTracker, yTracker);
            }
            if(m.getTile(j,i).getTileState() == 2){
                //drawImage(p, path_to_lava_texture, xTracker, yTracker);
            }
            if(m.getTile(j,i).getTileState() == 3){
                drawImage(p, "peppermintCandy.ppm", xTracker, yTracker);
            }
            if(m.getTile(j,i).getTileState() == 4){
                drawImage(p, "muddySwamp.ppm", xTracker, yTracker);
            }
            if(m.getTile(j,i).getTileState() == 5){
                //drawImage(p, path_to_teleport_texture, xTracker, yTracker);
            }
            if(m.getTile(j,i).getTileState() == 6){
                //drawImage(p, path_to_start_texture, xTracker, yTracker);
            }
            if(m.getTile(j,i).getTileState() == 7){
                //drawImage(p, path_to_finish_texture, xTracker, yTracker);
            }
        xTracker+=30;
        }
        yTracker+=30;
        xTracker = 0;
    }

}
void drawPlayer(SDL_Plotter& p, Player& play ){
    int x = play.getX() * 30;
    int y = play.getY() * 30;
    //Add logic to change texture based on player direction
    drawImage(p, "playerTemp.ppm", x,y);
}
void drawEnemy(SDL_Plotter& p, Enemy& en){
    int x = en.getX()*30;
    int y = en.getY()*30;
    drawImage(p, "kingcandy.ppm", x, y);
}



int main (int argc, char ** argv) {
    bool onTitleScreen = true;
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

    //Title screen

        drawImage(plot, "candyTitleS.PPM", 0,0);
        plot.update();

        while(!plot.getQuit() && onTitleScreen){
            if(plot.kbhit()) {
                onTitleScreen = false;
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

        drawMaze(plot, maze);
        drawPlayer(plot, player);
        updateEnemy(enemy, player, maze);
        drawEnemy(plot, enemy);
        if(player.getX() == enemy.getX() && player.getY() == enemy.getY()){
            player.startOver();
        }
        plot.update();

            plot.Sleep(30);

        }

        return 0;
    }
