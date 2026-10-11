// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 3/4, incomplete)
// pure3d::BillboardCutOffQuad::vfunc_6 @ 0x002b9ce0
extern "C" double sqrt(double);

struct Mat4 {
    float m[16];
};

struct V3 {
    float x, y, z;
};

void __cdecl FUN_002b8840(float *outA, float *outB, unsigned c, float *d, float *e, Mat4 *mat, V3 *dir);
void __cdecl FUN_002b8b30(float *outA, float *outB, unsigned c, float *d, float *e, Mat4 *mat, V3 *dir);
void __cdecl FUN_002b8e20(float *out, unsigned c, float *d, float len);

class BillboardCutOffQuad {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad04[0x38 - 4];
    char enabled;            // after pad
    char pad39[0xc8 - 0x39];
    unsigned f_c8;
    unsigned f_cc;
    unsigned f_d0;
    float f_d4[2];
    float f_dc[2];
    float f_e4[2];
    float f_ec[2];
    float f_f4;
    float f_f8;
    float f_fc;
    float f_100;
    float f_104;

    void FUN_002b9ce0(float *outA, float *outB, Mat4 *from, Mat4 *to);
};

void BillboardCutOffQuad::FUN_002b9ce0(float *outA, float *outB, Mat4 *from, Mat4 *to)
{
    if (enabled != 1)
        return;

    struct Frame {
        char pad00[8];
        float scaleB;
        float scaleC;
        float scaleD;
        float unused;
        V3 d;
        V3 t;
        char pad30[0x18];
        float scaleG;
        float len;
    } f;

    f.d.x = to->m[12] - from->m[12];
    f.d.y = to->m[13] - from->m[13];
    f.d.z = to->m[14] - from->m[14];
    f.len = (float)sqrt((double)(f.d.x * f.d.x + f.d.y * f.d.y) + (double)(f.d.z * f.d.z));

    double nx;
    double ny;
    union {
        float f;
        unsigned u;
    } absLen;
    absLen.f = f.len;
    absLen.u &= 0x7fffffff;
    if (absLen.f <= 1e-5f) {
        f.d.z = 0.0f;
        nx = 0.0;
        ny = 0.0;
    } else {
        double exact = 1.0 / (double)f.len;
        float inv = (float)exact;
        nx = exact * f.d.x;
        ny = inv * f.d.y;
        f.d.z = (float)(inv * f.d.z);
    }
    f.t.x = (float)-nx;
    f.t.y = (float)-ny;
    f.t.z = -f.d.z;

    f.scaleB = 1.0f;
    f.scaleD = 1.0f;
    f.scaleG = 1.0f;
    f.scaleC = 1.0f;
    f.unused = 1.0f;
    FUN_002b8840(&f.scaleB, &f.scaleD, f_c8, f_d4, f_dc, from, &f.t);
    FUN_002b8b30(&f.scaleG, &f.scaleC, f_cc, f_e4, f_ec, to, &f.t);
    FUN_002b8e20(&f.unused, f_d0, &f_104, f.len);

    double s1 = (double)f.scaleG * f.scaleB;
    double s2 = (double)f.scaleC * f.scaleD;
    double r1 = ((double)f_fc - f_100) * s2 + f_100;
    double r2 = ((double)f_f4 - f_f8) * s1 + f_f8;
    *outB = (float)(r1 * r2);
    *outA = (float)(s2 * s1 * f.scaleD);
}
