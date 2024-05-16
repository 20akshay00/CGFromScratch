#include <stdlib.h>

#include <SDL2/SDL.h>

#define WINDOW_WIDTH 600

void PutPixel(SDL_Renderer *renderer, int x, int y, SDL_Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawPoint(renderer, x, y);
}

void Draw(SDL_Renderer *renderer, SDL_Window *window)
{
    for (int i = 0; i < WINDOW_WIDTH; ++i)
    {
        SDL_Color color = {255, 0, 0, 255};
        PutPixel(renderer, i, i, color);
    }

    SDL_RenderPresent(renderer);
}

int main(void)
{
    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;

    // CREATE CANVAS
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_WIDTH, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    // DRAW CALL
    Draw(renderer, window);

    // EVENT HANDLING
    while (true)
    {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
