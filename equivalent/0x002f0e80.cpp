// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_002f0e80 @ 0x002f0e80
struct Vec3 { float x, y, z; };
struct Mat4 {
    float m[4][4];
    void FUN_0022b980();
    void FUN_0022c120();
    void FUN_0022c3b0(const Vec3 *in, Vec3 *out);
};
struct Volume {
    char pad0[0x38];
    int identity;           // 0x38
    char pad1[0x48 - 0x3c];
    Vec3 center;            // 0x48
    float rot[9];           // 0x54
};
bool FUN_002f0080(const Vec3 *a, const Vec3 *b, const Vec3 *c);
float FUN_002f0230(const Vec3 *a, const Vec3 *b, const Vec3 *c);

bool FUN_002f0e80(const Vec3 *p0, const Vec3 *p1, const Vec3 *p2, float margin, const Volume *vol, float *outT)
{
    Vec3 a = *p0;
    Vec3 b = *p2;
    Vec3 c;
    Vec3 d;
    Vec3 e;
    e.x = vol->center.x + margin;
    e.y = vol->center.y + margin;
    e.z = vol->center.z + margin;
    if (vol->identity == 0) {
        Mat4 mat;
        mat.FUN_0022b980();
        mat.m[0][0] = vol->rot[0];
        mat.m[0][1] = vol->rot[1];
        mat.m[0][2] = vol->rot[2];
        mat.m[1][0] = vol->rot[3];
        mat.m[1][1] = vol->rot[4];
        mat.m[1][2] = vol->rot[5];
        mat.m[2][0] = vol->rot[6];
        mat.m[2][1] = vol->rot[7];
        mat.m[2][2] = vol->rot[8];
        mat.FUN_0022c120();
        mat.FUN_0022c3b0(p0, &a);
        mat.FUN_0022c3b0(p2, &b);
        mat.FUN_0022c3b0(p1, &c);
        if (FUN_002f0080(&a, &c, &e))
            return false;
    }
    float t = FUN_002f0230(&a, &b, &e);
    *outT = t;
    if (t < 0.0f)
        return false;
    return t <= 1.0f;
}
