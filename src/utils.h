#include <vector>

// include guards to prevent including twice
#ifndef UTILS_H
#define UTILS_H
struct Color
{
    int r;
    int g;
    int b;

    Color(int r = 255, int g = 255, int b = 255) : r(r), g(g), b(b) {}
};

struct Point2D
{
    int x;
    int y;

    Point2D(int x = 0, int y = 0) : x(x), y(y) {}
    friend Point2D operator+(const Point2D &p1, const Point2D &p2)
    {
        Point2D res;
        res.x = p1.x + p2.x;
        res.y = p1.y + p2.y;

        return res;
    }
};

struct Point3D
{
    float x;
    float y;
    float z;

    Point3D(float x = 0., float y = 0., float z = 0.) : x(x), y(y), z(z) {}
    friend Point3D operator+(const Point3D &p1, const Point3D &p2)
    {
        Point3D res;
        res.x = p1.x + p2.x;
        res.y = p1.y + p2.y;
        res.z = p1.z + p2.z;

        return res;
    }
};

std::vector<int> DiscreteInterpolation(int, int, int, int);
std::vector<float> Interpolation(int, float, int, float);
#endif