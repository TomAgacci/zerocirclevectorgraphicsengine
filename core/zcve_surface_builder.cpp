#include "zcve_surface_builder.h"

std::vector<ZCFace> ZC_buildPolarSurface(
    float cx, float cy, float cz,
    float scale,
    int rSteps, int aSteps,
    float t)
{
    std::vector<std::vector<ZCPoint>> pts(rSteps+1, std::vector<ZCPoint>(aSteps+1));

    for(int ir=0; ir<=rSteps; ir++){
        float r = float(ir) / rSteps;
        for(int ia=0; ia<=aSteps; ia++){
            float a = (float(ia) / aSteps) * 6.2831853f;

            float x0 = r * std::cos(a);
            float y0 = r * std::sin(a);

            ZCPoint p = ZC_enginePoint(t, x0, y0);

            pts[ir][ia] = {
                cx + p.x * scale,
                cy + p.z * scale,
                cz + p.y * scale
            };
        }
    }

    std::vector<ZCFace> faces;
    for(int ir=0; ir<rSteps; ir++){
        for(int ia=0; ia<aSteps; ia++){
            faces.push_back({
                pts[ir][ia],
                pts[ir][ia+1],
                pts[ir+1][ia+1],
                pts[ir+1][ia]
            });
        }
    }

    return faces;
}

std::vector<ZCFace> ZC_buildCartesianSurface(
    float cx, float cy, float cz,
    float scale,
    int gridN,
    float t)
{
    std::vector<std::vector<ZCPoint>> pts(gridN+1, std::vector<ZCPoint>(gridN+1));

    for(int iy=0; iy<=gridN; iy++){
        float vy = (float(iy)/gridN)*2 - 1;
        for(int ix=0; ix<=gridN; ix++){
            float vx = (float(ix)/gridN)*2 - 1;

            ZCPoint p = ZC_enginePoint(t, vx, vy);

            pts[iy][ix] = {
                cx + p.x * scale,
                cy + p.z * scale,
                cz + p.y * scale
            };
        }
    }

    std::vector<ZCFace> faces;
    for(int iy=0; iy<gridN; iy++){
        for(int ix=0; ix<gridN; ix++){
            faces.push_back({
                pts[iy][ix],
                pts[iy][ix+1],
                pts[iy+1][ix+1],
                pts[iy+1][ix]
            });
        }
    }

    return faces;
}
