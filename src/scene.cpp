#include "scene.h"

Point2D Camera::ViewportToCanvas(float x, float y)
{
    return Point2D((int)(x * canvas.GetWidth() / viewport_width), (int)(y * canvas.GetHeight() / viewport_height));
}

Point2D Camera::ProjectVertexToCanvas(Point3D v)
{
    return ViewportToCanvas(v.x * viewport_distance / v.z, v.y * viewport_distance / v.z);
}

void Camera::RenderTriangle(TriangleData triangle, std::vector<Point2D> projected_vertices)
{
    canvas.DrawWireframeTriangle(
        projected_vertices[std::get<0>(triangle.v)],
        projected_vertices[std::get<1>(triangle.v)],
        projected_vertices[std::get<2>(triangle.v)],
        triangle.color);
}

void Camera::RenderMesh(Mesh m)
{
    std::vector<Point2D> projected_vertices(m.vertices.size());

    for (long unsigned int i = 0; i < projected_vertices.size(); ++i)
    {
        projected_vertices[i] = ProjectVertexToCanvas(m.vertices[i]);
    }

    for (auto &triangle : m.triangles)
    {
        RenderTriangle(triangle, projected_vertices);
    }
}