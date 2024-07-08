#include "scene.h"
#include <iostream>

// Camera::Camera(float w, float h, float d, Canvas c)
// {
//     viewport_width = w;
//     viewport_height = h;
//     viewport_distance = d;
//     canvas = c;
//     transform = Transform(1., Point3D(0., 0., 0.), Point3D(0., 0., 0.));
// }

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

void Camera::RenderInstance(MeshInstance instance)
{
    std::vector<Point2D> projected_vertices(instance.mesh.vertices.size());

    for (long unsigned int i = 0; i < projected_vertices.size(); ++i)
    {
        projected_vertices[i] = ProjectVertexToCanvas(
            transform.ApplyInverse(
                instance.transform.Apply(
                    instance.mesh.vertices[i])));
    }

    for (auto &triangle : instance.mesh.triangles)
    {
        RenderTriangle(triangle, projected_vertices);
    }
}

void Scene::Render()
{
    for (auto &instance : instances)
    {
        camera->RenderInstance(instance);
    }
}