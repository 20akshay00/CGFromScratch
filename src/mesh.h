#include <vector>
#include <tuple>
#include "utils.h"

class TriangleData
{
public:
    TriangleData(int, int, int, Color);
    std::tuple<int, int, int> v; // vertex ids
    Color color;
};

class Mesh
{
public:
    std::vector<Point3D> vertices;
    std::vector<TriangleData> triangles;
};

class MeshInstance
{
public:
    Mesh mesh;
    Transform transform;
    MeshInstance(Mesh &mesh, Transform transform) : mesh(mesh), transform(transform) {}
};