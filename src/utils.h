#include <vector>

struct Color
{
    int r;
    int g;
    int b;

    Color(int r, int g, int b) : r(r), g(g), b(b) {}
};

struct Point
{
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}
};

std::vector<int> DiscreteInterpolation(int, int, int, int);
std::vector<float> Interpolation(int, float, int, float);
