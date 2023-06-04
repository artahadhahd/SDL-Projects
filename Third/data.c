#include "data.h"
#include <SDL2/SDL.h>

void getPlatform(struct NecessaryData *data)
{
#ifdef _WIN32
    data->platform = PLATORM_WINDOWS_C;
#elif defined(__linux__)
    data->platform = PLATFORM_LINUX_C;
#else
    data->platform = PLATFORM_UNKNOWN_C;
#endif
}

void getScreenResolution(struct NecessaryData *data)
{
    SDL_DisplayMode ScreenRes;
	if (SDL_GetCurrentDisplayMode(0, &ScreenRes)) {
        printf("%s:%s\n", __FILE__, SDL_GetError());
        exit(10);
    }

    data->resolution[0] = ScreenRes.w;
    data->resolution[1] = ScreenRes.h;
}

void printData(struct NecessaryData *data)
{
    printf("Platform: %c\nScreen Resolution: %dx%d\nRunning: %d\n",
        data->platform, data->resolution[0], data->resolution[1], data->isRunning);
}
