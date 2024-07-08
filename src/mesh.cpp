#include "mesh.h"

TriangleData::TriangleData(int v1, int v2, int v3, Color c)
{
    v = {v1, v2, v3};
    color = c;
}