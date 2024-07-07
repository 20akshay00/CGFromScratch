#include <bits/stdc++.h>
#include "canvas.h"

Canvas::Canvas(int w, int h, SDL_Renderer *renderer)
{
    height = h;
    width = w;
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height);
    texture_buffer = new uint32_t[width * height];
}

void Canvas::UpdateTexture()
{
    SDL_UpdateTexture(texture, NULL, texture_buffer, width * sizeof(uint32_t));
}

void Canvas::PutPixel(Point p, Color color)
{
    int Sx = width / 2 + p.x;
    int Sy = height / 2 - p.y - 1;

    texture_buffer[(Sy * width) + Sx] = 0xFF000000 | (std::clamp(color.r, 0, 255) << 16) | (std::clamp(color.b, 0, 255) << 8) | std::clamp(color.g, 0, 255);
}

void Canvas::SetBackground(Color color)
{
    for (int i = -width / 2; i < width / 2; ++i)
    {
        for (int j = -height / 2; j < height / 2; ++j)
        {
            PutPixel(Point(i, j), color);
        }
    }
}

void Canvas::DrawLine(Point p1, Point p2, Color color)
{
    if (abs(p2.x - p1.x) > abs(p2.y - p1.y))
    {
        if (p1.x > p2.x) // enforce convention P1 lies to the left of P2
        {
            std::swap(p1, p2);
        }

        std::vector<int> ys = DiscreteInterpolation(p1.x, p1.y, p2.x, p2.y);

        for (int x = p1.x; x <= p2.x; ++x)
        {
            PutPixel(Point(x, ys[x - p1.x]), color);
        }
    }
    else
    {
        if (p1.y > p2.y) // enforce convention P1 lies to the left of P2
        {
            std::swap(p1, p2);
        }

        std::vector<int> xs = DiscreteInterpolation(p1.y, p1.x, p2.y, p2.x);

        for (int y = p1.y; y <= p2.y; ++y)
        {
            PutPixel(Point(xs[y - p1.y], y), color);
        }
    }
}