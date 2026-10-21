// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 4/4)
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
// unrounded with 0 and rounded with the squared length and for t. Each sum is one statement per term, in the
// listing's order (MSVC 7.1 reorders a sum written as one expression).
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
    hulk_freg dotx = pz * dz;
    dotx += py * dy;
    dotx += px * dx;
    volatile float dot = dotx;
    hulk_freg s;
    if (dotx <= 0.0f) {
        s = (hulk_freg)pzr * pzr;
        s += (hulk_freg)pyr * pyr;
        s += px * px;
        return sqrt(s);
    }
    hulk_freg len2 = (hulk_freg)dz * dz;
    len2 += (hulk_freg)dx * dx;
    len2 += (hulk_freg)dy * dy;
    if (len2 <= dot) {
        hulk_freg ex = p->x - b.x;
        hulk_freg ey = p->y - b.y;
        hulk_freg ez = p->z - b.z;
        s = ez * ez;
        s += ey * ey;
        s += ex * ex;
        return sqrt(s);
    }
    // The original's temporaries st = d*t, c = a + st and e = p - c: MSVC keeps some members in x87 registers
    // (unrounded: hulk_freg) and stores the others (rounded); written as structs so MSVC 7.1 makes the same choice.
    hulk_freg t = dot / len2;
    struct { hulk_freg x; float y, z; } st;
    st.x = dx * t;
    st.y = dy * t;
    st.z = dz * t;
    struct { hulk_freg x, y; float z; } c;
    c.x = st.x + a.x;
    c.y = st.y + a.y;
    c.z = st.z + a.z;
    struct { float x; hulk_freg y, z; } e;
    e.x = p->x - c.x;
    e.y = p->y - c.y;
    e.z = p->z - c.z;
    s = e.z * e.z;
    s += e.y * e.y;
    s += (hulk_freg)e.x * e.x;
    return sqrt(s);
}
