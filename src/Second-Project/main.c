#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <stdio.h>
#include "keyboard.h"
#include "button.h"

int main(void)
{
	if (SDL_Init(SDL_INIT_VIDEO)) {
		printf("Failed to start application! @ main.c\n%s\n", SDL_GetError());
		return 120;
	}

	SDL_DisplayMode ScreenResolution;
	if (SDL_GetCurrentDisplayMode(0, &ScreenResolution)) {
		printf("Failed to get screen resolution @ main.c !\n%s\nCannot continue!\n", SDL_GetError());
		exit(90);
	}
	struct WindowData wData = { .Height = ScreenResolution.h - 10, .Width = ScreenResolution.w };
	SDL_Window *window = NULL;
	window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			wData.Width, wData.Height, SDL_WINDOW_OPENGL);
	if (window == NULL) {
		printf("Failed to init: `window` @ main.c:\n%s\nCannot continue!\n", SDL_GetError());
		exit(120);
	}
	SDL_GLContext *Context = SDL_GL_CreateContext(window);
	SDL_Renderer *renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL) puts("WARNING: Failed to init: renderer! @ main.c");
	SDL_SetRenderDrawColor(renderer, 0xEF, 0xEF, 0xEF, 0x64);
	SDL_RenderClear(renderer);
	SDL_Rect topnav = { .x = 0, .y = 0, .w = wData.Width, .h = 25 }; // Readability reasons
	SDL_SetRenderDrawColor(renderer, 0xDF, 0xDF, 0xDF, 0xFF);
	SDL_RenderFillRect(renderer, &topnav);
	SDL_RenderPresent(renderer);

	SDL_Event event;
	while (1) {
		SDL_RenderPresent(renderer);
		while (SDL_PollEvent(&event)) {
			switch(event.type) {
			case SDL_QUIT:
				SDL_DestroyWindow(window);
				SDL_Quit();
				return 0;
			case SDL_KEYDOWN:
				handleKeyboardInput(&event.key.keysym, window, &wData);
				break;
			default:
				break;
			}
		}
		SDL_Delay(20);
	}
}