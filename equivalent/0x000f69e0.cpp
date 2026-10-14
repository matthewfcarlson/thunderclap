// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000f69e0 @ 0x000f69e0
struct Vec3_f69e0 { float x, y, z; };

union FloatBits_f69e0 {
    float f;
    unsigned int u;
};

struct Box_f69e0 {
    Vec3_f69e0 min;
    Vec3_f69e0 max;
};

struct Bounds_f69e0 {
    char pad00[0x14];
    Box_f69e0 box;
};

// Extent of the bounds: |max - min| per component.
void __cdecl FUN_000f69e0(Bounds_f69e0 *bounds, Vec3_f69e0 *out)
{
    Box_f69e0 b = bounds->box;
    FloatBits_f69e0 d;
    d.f = b.max.x - b.min.x;
    d.u &= 0x7fffffff;
    out->x = d.f;
    d.f = b.max.y - b.min.y;
    d.u &= 0x7fffffff;
    out->y = d.f;
    d.f = b.max.z - b.min.z;
    d.u &= 0x7fffffff;
    out->z = d.f;
}
