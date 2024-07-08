#include <vector>

// include guards to prevent including twice
#ifndef UTILS_H
#define UTILS_H
struct Color
{
    int r;
    int g;
    int b;

    Color(int r, int g, int b) : r(r), g(g), b(b) {}
};

struct Point2D
{
    int x;
    int y;

    Point2D(int x = 0, int y = 0) : x(x), y(y) {}
};

struct Point3D
{
    float x;
    float y;
    float z;

    Point3D(float x = 0., float y = 0., float z = 0.) : x(x), y(y), z(z) {}
};

std::vector<int> DiscreteInterpolation(int, int, int, int);
std::vector<float> Interpolation(int, float, int, float);
#endif