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
    int GetWidth();
    int GetHeight();

    void UpdateTexture(void);
    void PutPixel(Point2D, Color);
    void SetBackground(Color);
    void DrawLine(Point2D, Point2D, Color);
    void DrawWireframeTriangle(Point2D, Point2D, Point2D, Color);
    void DrawFilledTriangle(Point2D, Point2D, Point2D, Color);

    void DrawShadedTriangle(Point2D, Point2D, Point2D, Color);
    void DrawShadedTriangle(Point2D, Point2D, Point2D, Color, float, float, float);
};