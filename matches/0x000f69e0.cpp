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
extern "C" void __cdecl FUN_000f69e0(void *bounds, void *out)
{
    Box_f69e0 b = ((Bounds_f69e0 *)bounds)->box;
    FloatBits_f69e0 d;
    d.f = b.max.x - b.min.x;
    d.u &= 0x7fffffff;
    ((Vec3_f69e0 *)out)->x = d.f;
    d.f = b.max.y - b.min.y;
    d.u &= 0x7fffffff;
    ((Vec3_f69e0 *)out)->y = d.f;
    d.f = b.max.z - b.min.z;
    d.u &= 0x7fffffff;
    ((Vec3_f69e0 *)out)->z = d.f;
}
