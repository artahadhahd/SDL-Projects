#include <SDL2/SDL.h>

struct WindowData {
	volatile _Bool isFullscreen;
	const int Height;
	const int Width;
};

void handleKeyboardInput(SDL_Keysym *input, SDL_Window *win, struct WindowData *data);
