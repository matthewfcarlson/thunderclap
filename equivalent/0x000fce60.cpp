// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_000fce60 @ 0x000fce60
struct Vec3_fce60 { float x, y, z; };

struct Quat_fce60 {
    float x, y, z, w;
    void FUN_0022baf0(const Vec3_fce60 *axis, float angle);
    void FUN_0022c3b0(const Vec3_fce60 *in, Vec3_fce60 *out);
};

extern "C" float FUN_00224ea0(float y, float x);
extern "C" void FUN_00224d70(float angle, Vec3_fce60 *v);
extern float DAT_004a1aa0;
extern float DAT_004a1aa4;
extern float DAT_004a1aa8;

union FloatBits_fce60 {
    float f;
    unsigned int u;
};

void FUN_000fce60(Quat_fce60 *rot, Vec3_fce60 *axis, int unused2, int unused3, float a4, float a5, Vec3_fce60 *out)
{
    FloatBits_fce60 fy;
    fy.f = axis->y;
    fy.u &= 0x7fffffff;

    if (fy.f <= 0.001f) {
        Quat_fce60 q;
        Vec3_fce60 up;
        q.FUN_0022baf0(axis, -(FUN_00224ea0(a4, a5) + 3.14159274101257f));
        up.x = 0.0f;
        up.y = 1.0f;
        up.z = 0.0f;
        q.FUN_0022c3b0(&up, out);
    } else {
        Vec3_fce60 fwd;
        Vec3_fce60 w;
        fwd.x = 0.0f;
        fwd.y = 0.0f;
        fwd.z = 1.0f;
        rot->FUN_0022c3b0(&fwd, &w);
        float heading = FUN_00224ea0(w.x, w.z);
        float angle = (FUN_00224ea0(a4, a5) + 3.14159274101257f) + heading;
        out->x = DAT_004a1aa0;
        out->y = DAT_004a1aa4;
        out->z = DAT_004a1aa8;
        FUN_00224d70(angle, out);
        out->x = DAT_004a1aa0;
        out->y = DAT_004a1aa4;
        out->z = DAT_004a1aa8;
        FUN_00224d70(angle, out);
    }

    FloatBits_fce60 b4, b5;
    b4.f = a4;
    b4.u &= 0x7fffffff;
    b5.f = a5;
    b5.u &= 0x7fffffff;
    float s = (b4.f > b5.f) ? b4.f : b5.f;
    out->x = s * out->x;
    out->y = s * out->y;
    out->z = s * out->z;
}
