#include <vector>
#include "mesh.h"
#include "canvas.h"

class Camera
{
    float viewport_width;
    float viewport_height;
    float viewport_distance;
    Canvas canvas;
    Transform transform;

public:
    Camera(float w, float h, float d, Canvas c, Transform t) : viewport_width(w), viewport_height(h), viewport_distance(d), canvas(c), transform(t) {}
    Point2D ViewportToCanvas(float, float);
    Point2D ProjectVertexToCanvas(Point3D);
    void RenderTriangle(TriangleData, std::vector<Point2D>);
    void RenderInstance(MeshInstance);
};

class Scene
{
public:
    Camera *camera;
    std::vector<Mesh> meshes;
    std::vector<MeshInstance> instances;
    void Render(void);
};