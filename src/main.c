#include <SDL3/SDL.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    fflush(stdout);

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }

    printf("SDL INIT OK\n");
    fflush(stdout);

    SDL_Window *window = SDL_CreateWindow(
        "SDL3 Test",
        800,
        600,
        0
    );

    if (!window) {
        printf("Window failed: %s\n", SDL_GetError());
        return 1;
    }

    printf("WINDOW CREATED\n");
    fflush(stdout);

    SDL_Delay(5000);

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}