// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 8/8)
// FUN_000f6680 @ 0x000f6680
#include "compat/ptr.h"
extern "C" double sqrt(double);

struct Mat_f6680;

struct V3_f6680 {
    float x, y, z;
    void FUN_0022d180();
    void FUN_0022d260(const Mat_f6680 *m);
};

struct Mat_f6680 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(const V3_f6680 *axis, float angle);
};

struct Obj_f6680 {
    char pad0[0xdc];
    V3_f6680 b;
    V3_f6680 a;
    void FUN_00293a90(const V3_f6680 *v);
};

float FUN_00018a20(float x);

void FUN_000f6680(Obj_f6680 *p, float angle, float k)
{
    struct Frame {
        V3_f6680 a;
        V3_f6680 b;
        V3_f6680 c;
        Mat_f6680 m;
    } f;
    f.a = p->a;
    f.b = p->b;
    f.c.x = p->b.x;
    f.c.y = p->b.y;
    f.c.z = p->b.z;

    hulk_freg cx = f.c.y * f.a.z - f.c.z * f.a.y;
    hulk_freg cy = f.c.z * f.a.x - f.a.z * f.c.x;
    hulk_freg cz = f.a.y * f.c.x - f.c.y * f.a.x;
    f.c.x = cx;
    f.c.y = cy;
    f.c.z = cz;

    double la = sqrt(f.a.y * f.a.y + f.a.z * f.a.z + f.a.x * f.a.x);
    double dot = f.b.z * f.a.z + f.b.y * f.a.y + f.b.x * f.a.x;
    hulk_freg lb = sqrt(f.b.z * f.b.z + f.b.y * f.b.y + f.b.x * f.b.x);
    hulk_freg r = FUN_00018a20((float)(dot / la * lb));
    f.b.FUN_0022d180();

    if ((k < 0.0f && r > 0.196349546f) || (k > 0.0f && r < 2.94524312f)) {
        f.m.FUN_0022b980();
        f.m.FUN_0022baf0(&f.c, k);
        f.b.FUN_0022d260(&f.m);
    }
    f.m.FUN_0022b980();
    f.m.FUN_0022baf0(&f.a, -angle);
    f.b.FUN_0022d260(&f.m);
    p->FUN_00293a90(&f.b);
}
