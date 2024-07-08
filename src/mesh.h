#include <vector>
#include <tuple>
#include "utils.h"

class TriangleData
{
public:
    std::tuple<int, int, int> v; // vertex ids
    Color color;
};

class Mesh
{
public:
    std::vector<Point3D> vertices;
    std::vector<TriangleData> triangles;
};