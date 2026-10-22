// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 4/4)
// FUN_002304b0 @ 0x002304b0
#include "compat/ptr.h"
extern "C" double sqrt(double);

// Distance between two 3D line segments.
struct Segment_2304b0 {
    float p0x, p0y, p0z;
    float p1x, p1y, p1z;

    hulk_freg FUN_002304b0(const Segment_2304b0* o);
};

hulk_freg Segment_2304b0::FUN_002304b0(const Segment_2304b0* o)
{
    float d1x = p1x - p0x;
    float d1y = p1y - p0y;
    float d1z = p1z - p0z;
    float d2x = o->p1x - o->p0x;
    float d2y = o->p1y - o->p0y;
    float d2z = o->p1z - o->p0z;
    float rx = p0x - o->p0x;
    float ry = p0y - o->p0y;
    float rz = p0z - o->p0z;

    float a = d1z * d1z + d1x * d1x + d1y * d1y;
    float b = d2z * d1z + d2y * d1y + d2x * d1x;
    float c = d2z * d2z + d2y * d2y + d2x * d2x;
    float d = rz * d1z + ry * d1y + rx * d1x;
    float e = rz * d2z + ry * d2y + rx * d2x;

    double s;
    double t;
    double denom = c * a - b * b; // compared unrounded
    if (denom < 1e-5f) {
        s = 0.0f;
        if (b > c)
            t = d / b;
        else
            t = e / c;
    } else {
        float inv = 1.0f / denom;
        s = (e * b - d * c) * inv;
        t = (e * a - d * b) * inv;
    }

    volatile float c2x = d2x * t;
    volatile float c2y = d2y * t;
    double c2z = t * d2z;
    volatile float c1z = d1z * s;
    volatile float xx = d1x * s + rx;
    double yy = d1y * s + ry;
    volatile float zz = c1z + rz;
    volatile float dx = xx - c2x;
    volatile float dy = yy - c2y;
    double dz = zz - c2z;
    double zy = dz * dz + dy * dy; // keep the original's summation order
    return sqrt(zy + dx * dx);
}
