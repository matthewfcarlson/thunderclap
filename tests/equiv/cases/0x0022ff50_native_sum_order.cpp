// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_0022ff50 @ 0x0022ff50
#include "compat/ptr.h"
extern "C" double sqrt(double);

struct Vec3_22ff50 { float x, y, z; };

// Distance from point p to the segment [a, b].
class Segment_22ff50 {
public:
    Vec3_22ff50 a;
    Vec3_22ff50 b;
    hulk_freg FUN_0022ff50(Vec3_22ff50 *p);
};

// x87: the segment's deltas go through the frame (rounded); the point's x delta stays in a register, its y and z
// deltas are rounded copies for the distance but unrounded in the dot product; the dot product is compared
// unrounded with 0 and rounded with the squared length and for t
hulk_freg Segment_22ff50::FUN_0022ff50(Vec3_22ff50 *p)
{
    volatile float dx = b.x - a.x;
    volatile float dy = b.y - a.y;
    volatile float dz = b.z - a.z;
    hulk_freg px = p->x - a.x;
    hulk_freg py = p->y - a.y;
    volatile float pyr = py;
    hulk_freg pz = p->z - a.z;
    volatile float pzr = pz;
    hulk_freg dotx = pz * dz + py * dy + px * dx;
    volatile float dot = dotx;
    if (dotx <= 0.0f)
        return (hulk_freg)sqrt((hulk_freg)pzr * pzr + (hulk_freg)pyr * pyr + px * px);
    hulk_freg len2 = (hulk_freg)dz * dz + (hulk_freg)dx * dx + (hulk_freg)dy * dy;
    if (len2 <= dot) {
        hulk_freg ex = p->x - b.x;
        hulk_freg ey = p->y - b.y;
        hulk_freg ez = p->z - b.z;
        return (hulk_freg)sqrt(ez * ez + ey * ey + ex * ex);
    }
    hulk_freg t = dot / len2;
    hulk_freg cx = dx * t + a.x;
    volatile float sy = dy * t;
    volatile float sz = dz * t;
    hulk_freg cy = sy + a.y;
    volatile float cz = sz + a.z;
    volatile float ex = p->x - cx;
    hulk_freg ey = p->y - cy;
    hulk_freg ez = p->z - cz;
    return (hulk_freg)sqrt(ez * ez + ey * ey + (hulk_freg)ex * ex);
}
