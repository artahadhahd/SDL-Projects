#include "keyboard.h"

/* Handle Keyboard Inputs on a specific screen*/
void handleKeyboardInput(SDL_Keysym *input, SDL_Window *win, struct WindowData *data)
{
	switch (input->sym) {
	case SDLK_ESCAPE:
		puts("Escaped lol");
		break;
	case SDLK_F11:
		data->isFullscreen = !data->isFullscreen;
		if (data->isFullscreen)
			// SDL_SetWindowFullscreen(win, SDL_WINDOW_FULLSCREEN);
			SDL_SetWindowFullscreen(win, SDL_WINDOW_FULLSCREEN_DESKTOP);
		else SDL_SetWindowFullscreen(win, 0);
		break;
	}
}
