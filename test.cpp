#include "SDL_Plotter.h"

int main(int argc, char** argv) {
    SDL_Plotter g(500, 500);   // rows, cols
    while (!g.getQuit()) {
        for (int i = 100; i < 200; i++)
            for (int j = 100; j < 200; j++)
                g.plotPixel(i, j, 255, 0, 0);
        g.update();
    }
    return 0; 
}

