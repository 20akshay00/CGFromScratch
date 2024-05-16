#include <stdlib.h>
#include <SDL2/SDL.h>
#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 400

void PutPixel(uint32_t *texture_buffer, int x, int y, int r, int g, int b)
{
    int Sx = WINDOW_WIDTH / 2 + x;
    int Sy = WINDOW_HEIGHT / 2 - y;

    texture_buffer[(Sy * WINDOW_WIDTH) + Sx] = 0xFF000000 | (r << 16) | (b << 8) | g;
}

void DrawToCanvas(uint32_t *canvas_buffer)
{
    for (int i = -WINDOW_WIDTH / 2; i < WINDOW_WIDTH / 2; ++i)
    {
        for (int j = -WINDOW_HEIGHT / 2; j < WINDOW_HEIGHT / 2; ++j)
        {
            PutPixel(canvas_buffer, i, j, (255 * (i + WINDOW_WIDTH / 2)) / WINDOW_WIDTH, (255 * (j + WINDOW_HEIGHT / 2)) / WINDOW_HEIGHT, 0);
        }
    }
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
    SDL_Texture *canvas_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WINDOW_WIDTH, WINDOW_HEIGHT);
    uint32_t *canvas_buffer = new uint32_t[WINDOW_WIDTH * WINDOW_HEIGHT];

    // UPDATE TEXTURE DATA
    DrawToCanvas(canvas_buffer);
    SDL_UpdateTexture(canvas_texture, NULL, canvas_buffer, WINDOW_WIDTH * sizeof(uint32_t));

    // DRAW TEXTURE TO CANVAS
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, canvas_texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    // EVENT HANDLING
    while (true)
    {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
    }

    SDL_DestroyTexture(canvas_texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
