#pragma once
#include <cmath>

struct ZCPoint {
    float x, y, z;
};

inline float ZC_P(float t, float x, float y, const float u[3]) {
    float r = std::sqrt(x*x + y*y);
    float a = std::atan2(y, x);
    return
        std::sin(a + u[0]*t) +
        std::sin(2*a + u[1]*t + r) +
        std::sin(3*a + u[2]*t + r*r);
}

inline ZCPoint ZC_enginePoint(float t, float x, float y,
                              const float u_def[3] = {1,2,3},
                              const float u_hgt[3] = {3,2,1})
{
    float r = std::sqrt(x*x + y*y) + 0.2f * ZC_P(t, x, y, u_def);
    float a = std::atan2(y, x);

    float px = r * std::cos(a);
    float py = r * std::sin(a);
    float pz = 0.5f * ZC_P(t, x, y, u_hgt);

    return { px, py, pz };
}
