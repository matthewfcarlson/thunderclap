// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000f69e0 @ 0x000f69e0
struct Vec3 { float x, y, z; };

union FloatBits {
    float f;
    unsigned int u;
};

struct Box {
    Vec3 min;
    Vec3 max;
};

struct Bounds {
    char pad00[0x14];
    Box box;
};

// Extent of the bounds: |max - min| per component.
void __cdecl FUN_000f69e0(Bounds *bounds, Vec3 *out)
{
    Box b = bounds->box;
    FloatBits d;
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
