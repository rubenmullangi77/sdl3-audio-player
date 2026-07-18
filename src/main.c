#include <SDL3/SDL.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }

    printf("SDL INIT OK\n");

    SDL_Window *window = SDL_CreateWindow(
        "SDL3 audio player",
        800,
        600,
        0
    );


    if (!window) {
        printf("Window failed: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Event event;
    bool running = true;
    while(running)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_EVENT_QUIT)
            {
                running = false;
            }
            
        }

    }


    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}