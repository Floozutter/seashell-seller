#include <SDL2/SDL.h>
#include "constants.h"

int main(int argc, char * argv[]) {
	// Initialize SDL.
	if (SDL_Init(SDL_INIT_VIDEO != 0)) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
	}
	// Create window.
	SDL_Window * const window = SDL_CreateWindow(
		"Seashell Seller",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		W_WIDTH, W_HEIGHT,
		0
	);
	if (window == NULL) {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        return 1;
	}
	// Create renderer.
	SDL_Renderer * const renderer = SDL_CreateRenderer(
		window, -1, SDL_RENDERER_SOFTWARE
	);
	if (renderer == NULL) {
		SDL_Log("Unable to create renderer: %s", SDL_GetError());
		return 1;
	}
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	
	SDL_Delay(3000);
	
	// Clean up and quit.
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
