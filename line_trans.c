#include <SDL2/SDL.h>
#include <stdio.h>
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

    SDL_Window* window = SDL_CreateWindow("Translation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    int pivot_x = 200, pivot_y = 200;
    int x = 400, y = 500;
    int translation_speed = 2; // I am Speed

    while (!quit) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        x += translation_speed;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawLine(renderer, pivot_x, pivot_y, x, y);

        SDL_RenderPresent(renderer);

        SDL_Delay(16); 
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
