#include <SDL2/SDL.h>
#include "constants.h"

int main(int argc, char * argv[]) {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window * const window = SDL_CreateWindow(
		"Seashell Seller",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		W_WIDTH, W_HEIGHT,
		0
	);

	SDL_Renderer * const renderer = SDL_CreateRenderer(
		window, -1, SDL_RENDERER_SOFTWARE
	);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	SDL_Delay(3000);

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
