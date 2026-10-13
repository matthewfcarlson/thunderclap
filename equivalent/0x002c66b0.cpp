// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_002c66b0 @ 0x002c66b0
struct Vec3 {
    float x, y, z;
    void FUN_0022d180();
};

struct Mat {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(const Vec3 *axis, float angle);
    void FUN_0022be40(const Vec3 *pos);
};

float __cdecl FUN_00018a20(float v);
void __cdecl FUN_002c4a20(float width, Mat *m, int a, int b, int c, int d);
void __cdecl FUN_002c5260(float w0, const Vec3 *from, float w1, const Vec3 *to, int a, int b, int c, int d);

struct Frame {
    Vec3 axis;
    Vec3 dir;
    Mat m;
};

static float Abs(float v)
{
    return v < 0.0f ? -v : v;
}

void FUN_002c66b0(float width, const Vec3 *p1, const Vec3 *p2, int a, int b, int c, int d)
{
    Frame f;
    float angle;
    f.dir.x = p1->x - p2->x;
    f.dir.y = p1->y - p2->y;
    f.dir.z = p1->z - p2->z;
    f.dir.FUN_0022d180();
    f.axis.x = f.dir.z;
    f.axis.y = 0.0f;
    f.axis.z = -f.dir.x;
    if (Abs(f.axis.x) <= 1e-05f && Abs(f.axis.z) <= 1e-05f) {
        f.axis.x = 1.0f;
        f.axis.y = 0.0f;
        f.axis.z = 0.0f;
        angle = 3.1415927f;
    } else {
        angle = -FUN_00018a20(f.dir.y);
    }
    f.m.FUN_0022b980();
    f.m.FUN_0022baf0(&f.axis, angle);
    f.m.FUN_0022be40(p1);
    FUN_002c4a20(width, &f.m, a, b, c, d);
    f.m.FUN_0022baf0(&f.axis, angle + 3.1415927f);
    f.m.FUN_0022be40(p2);
    FUN_002c4a20(width, &f.m, a, b, c, d);
    FUN_002c5260(width, p1, width, p2, a, b, c, d);
}
