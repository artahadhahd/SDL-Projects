#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h> // sudo pacman -S glu; sduo apt-get install libglfw3-dev libgl1-mesa-dev libglu1-mesa-dev

// https://wiki.libsdl.org/SDL2/SDL_Keycode

int main(void) {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		puts("Could not initialize Main Window! E200");
		exit(200);
	}

	SDL_Window *TitleWindow = NULL;
	TitleWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 680, 580, SDL_WINDOW_RESIZABLE);
	// SDL_Surface *SurfTitleWindow = SDL_GetWindowSurface(TitleWindow);
	// SDL_FillRect(SurfTitleWindow, NULL, SDL_MapRGB(SurfTitleWindow->format, 240, 200, 0));
	// SDL_UpdateWindowSurface(TitleWindow);
	if (TitleWindow == NULL)
		printf("Failed to initialize Screen!!! %s", SDL_GetError());

	SDL_Renderer *renderer = NULL;
	renderer = SDL_CreateRenderer(TitleWindow, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
		printf("Failed to init: renderer! %s", SDL_GetError());
	SDL_SetRenderDrawColor(renderer, 255, 122, 0, 255);

	SDL_Event event;
	int d = 1;
	while(1) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				goto EXIT_S;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_d) {
					for (int i = 0; i <= d; ++i)
						SDL_RenderDrawPoint(renderer, i, 100);
					d += 1;
				}
				SDL_RenderPresent(renderer);
				break;
			case SDL_KEYUP:
				printf("You released %c", event.key.keysym.sym);
				puts("");
				break;
			default:
				break;
			}
		}
		SDL_Delay(2); // Don't fry the CPU
	}
EXIT_S:
	puts("Exiting");
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(TitleWindow);
	SDL_Quit();

	return 0;
}
