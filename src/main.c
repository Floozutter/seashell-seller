#include <SDL.h>
#include "constants.h"

int main(int argc, char * argv[]) {
    // suppress unused parameter warnings
    (void)argc;
    (void)argv;
    // init SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "couldn't init SDL (%s)!", SDL_GetError());
        return 1;
    }
    // create window
    SDL_Window * const window = SDL_CreateWindow(
        "seashell seller",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        W_WIDTH, W_HEIGHT,
        0
    );
    if (window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "couldn't create window (%s)!", SDL_GetError());
        return 1;
    }
    // create renderer
    SDL_Renderer * const renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_RENDER, "couldn't create renderer (%s)!", SDL_GetError());
        return 1;
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
    // clean up and quit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
