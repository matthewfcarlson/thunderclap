// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001eb7e0 @ 0x001eb7e0
struct Vec3_1eb7e0 {
    float x, y, z;
};

struct Impl_1eb7e0 {
    void FUN_001f42d0(int a, int b, Vec3_1eb7e0 v3, Vec3_1eb7e0 v4, Vec3_1eb7e0 v5, Vec3_1eb7e0 v6, int last);
};

struct Handle_1eb7e0 {
    Impl_1eb7e0 *impl;
};

struct Owner_1eb7e0 {
    Handle_1eb7e0 *handle;
    void FUN_001eb7e0(int a, int b, const Vec3_1eb7e0 *p3, const Vec3_1eb7e0 *p4, const Vec3_1eb7e0 *p5,
                      float f6, float f7, float f8, int p9);
};

void Owner_1eb7e0::FUN_001eb7e0(int a, int b, const Vec3_1eb7e0 *p3, const Vec3_1eb7e0 *p4, const Vec3_1eb7e0 *p5,
                         float f6, float f7, float f8, int p9)
{
    Vec3_1eb7e0 last;
    last.x = f6;
    last.y = f7;
    last.z = f8;
    (*handle).impl->FUN_001f42d0(a, b, *p3, *p4, *p5, last, p9);
}
