#pragma once
#include <vector>
#include "zcve_zero_circle.h"

struct ZCFace {
    ZCPoint a, b, c, d;
};

std::vector<ZCFace> ZC_buildPolarSurface(
    float cx, float cy, float cz,
    float scale,
    int rSteps, int aSteps,
    float t
);

std::vector<ZCFace> ZC_buildCartesianSurface(
    float cx, float cy, float cz,
    float scale,
    int gridN,
    float t
);
