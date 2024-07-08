#include <iostream>
#include "scene.h"

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 800

// void Draw(Canvas canvas)
// {
//     canvas.SetBackground(Color(101, 82, 77));
//     canvas.DrawFilledTriangle(Point2D(-200, -250), Point2D(200, 50), Point2D(20, 250), Color(127, 194, 155));
//     canvas.DrawShadedTriangle(Point2D(-200, -250), Point2D(200, 50), Point2D(20, 250), Color(127, 194, 155), 0.5, 0., 1.0);
// }

void Draw(Canvas canvas)
{
    canvas.SetBackground(Color(101, 82, 77));
    canvas.DrawFilledTriangle(Point2D(-200, -250), Point2D(200, 50), Point2D(20, 250), Color(127, 194, 155));
    canvas.DrawShadedTriangle(Point2D(-200, -250), Point2D(200, 50), Point2D(20, 250), Color(127, 194, 155), 0.5, 0., 1.0);
}

void SetupScene(Scene &scene)
{
    // color palette
    std::vector<Color> palette = {Color(247, 102, 95), Color(115, 214, 115), Color(167, 199, 231), Color(247, 242, 154), Color(145, 108, 207), Color(177, 247, 242)};

    // cube mesh
    Mesh cube;
    cube.vertices = {Point3D(1, 1, 1), Point3D(-1, 1, 1), Point3D(-1, -1, 1), Point3D(1, -1, 1), Point3D(1, 1, -1), Point3D(-1, 1, -1), Point3D(-1, -1, -1), Point3D(1, -1, -1)};
    cube.triangles = {
        {0, 1, 2, palette[0]},
        {0, 2, 3, palette[0]},
        {4, 0, 3, palette[1]},
        {4, 3, 7, palette[1]},
        {5, 4, 7, palette[2]},
        {5, 7, 6, palette[2]},
        {1, 5, 6, palette[3]},
        {1, 6, 2, palette[3]},
        {4, 5, 1, palette[4]},
        {4, 1, 0, palette[4]},
        {2, 6, 7, palette[5]},
        {2, 7, 3, palette[5]}};

    scene.meshes = {cube};
    scene.instances = {
        MeshInstance(cube, Transform(1., Point3D(0., 0., 0.), Point3D(-1.5, 0., 7.))),
        MeshInstance(cube, Transform(0.5, Point3D(0., 0., 0.), Point3D(1.5, 0., 7.)))};
}

int main(void)
{
    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;

    // CREATE WINDOW
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);

    // CREATE EMPTY SCENE
    Canvas canvas(WINDOW_WIDTH, WINDOW_HEIGHT, renderer);
    Camera camera(2., 1., 1., canvas, Transform(1., Point3D(0., 0., 0.), Point3D(0., 0., -1.)));
    Scene scene;
    scene.camera = &camera;

    // UPDATE TEXTURE DATA
    SetupScene(scene);
    scene.Render();
    canvas.UpdateTexture();

    // DRAW CANVAS TO WINDOW
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, canvas.texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    // EVENT HANDLING
    while (true)
    {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
