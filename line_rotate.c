/* 
    This is the implementation of line rotation in SDL(Simple DirectMedia Layer) 
    because graphics.h is obsolete and really fucking annoying to setup 
*/

/*
    I cannot use Turbo C for shit
    Use gcc -Isrc/Include -Lsrc/lib -o main main.c -lmingw32 -lSDL2main -lSDL2
    library can be downloaded from https://github.com/libsdl-org/SDL/releases

    How the fuck are people creating games using these technologies
*/


#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include <signal.h>

int quit = 0;

void handleSignal(int signum) {
    if (signum == SIGINT) {
        quit = 1;
    }
}

int main(int argc, char* argv[]) {
    signal(SIGINT, handleSignal);

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Rotation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    while (!quit) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        int pivot_x = 200, pivot_y = 200;
        int x = 400, y = 500;
        double degree = 30.0; 
        double radian = degree * 0.01745;
        int rotated_point_x, rotated_point_y;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawLine(renderer, pivot_x, pivot_y, x, y);

        rotated_point_x = (int)(pivot_x + ((x - pivot_x) * cos(radian) - (y - pivot_y) * sin(radian)));
        rotated_point_y = (int)(pivot_y + ((x - pivot_x) * sin(radian) + (y - pivot_y) * cos(radian)));

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawLine(renderer, pivot_x, pivot_y, rotated_point_x, rotated_point_y);

        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
