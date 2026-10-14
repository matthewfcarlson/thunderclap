// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001eb7e0 @ 0x001eb7e0
struct Vec3 {
    float x, y, z;
};

struct Impl {
    void FUN_001f42d0(int a, int b, Vec3 v3, Vec3 v4, Vec3 v5, Vec3 v6, int last);
};

struct Handle {
    Impl *impl;
};

struct Owner {
    Handle *handle;
    void FUN_001eb7e0(int a, int b, const Vec3 *p3, const Vec3 *p4, const Vec3 *p5,
                      float f6, float f7, float f8, int p9);
};

void Owner::FUN_001eb7e0(int a, int b, const Vec3 *p3, const Vec3 *p4, const Vec3 *p5,
                         float f6, float f7, float f8, int p9)
{
    Vec3 last;
    last.x = f6;
    last.y = f7;
    last.z = f8;
    (*handle).impl->FUN_001f42d0(a, b, *p3, *p4, *p5, last, p9);
}
