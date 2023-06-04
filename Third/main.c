#include <SDL2/SDL.h>
#include "data.h"

void startVideo(void);

int main(void)
{
    startVideo();

    struct NecessaryData data;
    getPlatform(&data);
    getScreenResolution(&data);
    data.isRunning = 1;

    SDL_Event e;
    while (data.isRunning) {
        switch (SDL_PollEvent(&e))
        {
        case 2:
            break;
        default:
            break;
        }
    }

    SDL_Quit();

    return 0;
}

void startVideo(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        puts("Couldn't start video");
		printf("%s:%s\n", __FILE__, SDL_GetError());
        exit(10);
    }
    puts("Started video successfully");
}