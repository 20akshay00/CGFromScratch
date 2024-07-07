#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <iostream>
#include "canvas.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 400

void Draw(Canvas canvas)
{
    canvas.SetBackground(Color(0, 0, 0));
    canvas.DrawLine(Point(-50, -200), Point(60, 240), Color(255, 255, 255));
}

int main(void)
{
    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;

    // CREATE CANVAS
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);

    // CREATE EMPTY TEXTURE
    Canvas canvas(WINDOW_WIDTH, WINDOW_HEIGHT, renderer);

    // UPDATE TEXTURE DATA
    Draw(canvas);
    canvas.UpdateTexture();

    // DRAW TEXTURE TO CANVAS
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, canvas.texture, NULL, NULL);
    SDL_RenderPresent(renderer);

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
