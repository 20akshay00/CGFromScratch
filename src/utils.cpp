#include <bits/stdc++.h>
#include "utils.h"

std::vector<int> DiscreteInterpolation(int i1, int d1, int i2, int d2)
{
    std::vector<int> ds(i2 - i1 + 1);

    if (i1 == i2)
    {
        ds[0] = d1;
    }
    else
    {
        float m = (float)(d2 - d1) / (i2 - i1); // slope
        float d = d1;                           // first point

        for (int idx = 0; idx <= (i2 - i1 + 1); ++idx)
        {
            ds[idx] = (int)d;
            d += m; // increment height by slope == change in y per unit change in x
        }
    }

    return ds;
}
