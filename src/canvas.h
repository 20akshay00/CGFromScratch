#include <SDL2/SDL.h>
#include "utils.h"

class Canvas
{
private:
    int height;
    int width;
    uint32_t *texture_buffer;

public:
    SDL_Texture *texture;

    Canvas(int, int, SDL_Renderer *);
    void UpdateTexture(void);
    void PutPixel(Point, Color);
    void SetBackground(Color);
    void DrawLine(Point, Point, Color);
    void DrawWireframeTriangle(Point, Point, Point, Color);
    void DrawFilledTriangle(Point, Point, Point, Color);

    void DrawShadedTriangle(Point, Point, Point, Color);
    void DrawShadedTriangle(Point, Point, Point, Color, float, float, float);
};