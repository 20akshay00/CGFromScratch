#include <vector>
#include "mesh.h"
#include "canvas.h"

class Camera
{
    float viewport_width;
    float viewport_height;
    float viewport_distance;
    Canvas canvas;

public:
    Camera(float w, float h, float d, Canvas c) : viewport_width(w), viewport_height(h), viewport_distance(d), canvas(c) {}
    Point2D ViewportToCanvas(float x, float y);
    Point2D ProjectVertexToCanvas(Point3D);
    void RenderTriangle(TriangleData, std::vector<Point2D>);
    void RenderMesh(Mesh);
};

class Scene
{
    std::vector<Mesh> objects;
};