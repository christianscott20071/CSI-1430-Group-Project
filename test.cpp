#include "SDL_Plotter.h"

int main(int argc, char** argv) {
    SDL_Plotter g(1000, 1000);   // rows, cols
    while (!g.getQuit()) {
        for (int i = 10; i < 30; i++)
            for (int j = 10; j < 30; j++)
                g.plotPixel(i, j, 255, 0, 0);
        g.update();
    }
    return 0; 
}
