// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 28/28)
// CHand2HandAgent::vfunc_15 @ 0x00101fe0
extern "C" double sqrt(double);

struct Vec3_101fe0 {
    float x, y, z;
    float FUN_0022d110() throw();
    char FUN_0022d2b0(const Vec3_101fe0 *z, float eps) throw();
};

struct V2_101fe0 {
    float a, b;
};

struct World;
struct Ctx;

union FloatBits_101fe0 {
    float f;
    unsigned int u;
};

float __cdecl FUN_0010ae50(World *w, Ctx *c, float thr, Vec3_101fe0 *a, Vec3_101fe0 *b, int p, int q) throw();

class CHand2HandAgent {
public:
    virtual void vfunc_0() throw();
    virtual void vfunc_1() throw();
    virtual void vfunc_2() throw();
    virtual void vfunc_3() throw();
    virtual void vfunc_4() throw();
    virtual void vfunc_5() throw();
    virtual void vfunc_6() throw();
    virtual void vfunc_7() throw();
    virtual void vfunc_8() throw();
    virtual void vfunc_9() throw();
    virtual void vfunc_10() throw();
    virtual void vfunc_11() throw();
    virtual void vfunc_12() throw();
    virtual void vfunc_13() throw();
    virtual void vfunc_14() throw();
    virtual char vfunc_15(World *a1, Ctx *a2);
    char pad04[0x5c];
    char b60;
    char pad61[3];
    float f64;
    char pad68[0x88 - 0x68];
    Vec3_101fe0 v88;
    char pad94[0xa4 - 0x94];
    Vec3_101fe0 va4;
    char padb0[0xc8 - 0xb0];
    float fc8;
    char padcc[0xd4 - 0xcc];
    V2_101fe0 vd4;
    V2_101fe0 vdc;
    float fe4;
    float fe8;
    Vec3_101fe0 vec;
    Vec3_101fe0 vf8;
    Vec3_101fe0 v104;
    Vec3_101fe0 v110;
    float f11c;
    float f120;
    char pad124[0x144 - 0x124];
    Vec3_101fe0 v144;
    char pad150[0x180 - 0x150];
    float f180;
};

char CHand2HandAgent::vfunc_15(World *a1, Ctx *a2)
{
    struct Frame {
        char pad0[3];
        char res;
        float L2;
        float Lb;
        float absTmp;
        Vec3_101fe0 C;
        Vec3_101fe0 B;
        Vec3_101fe0 E;
        Vec3_101fe0 A;
        Vec3_101fe0 D;
        Vec3_101fe0 O;
    } f;

    f.res = 1;
    f.A.y = 0.0f;
    f.A.x = vec.x - v88.x;
    f.B.y = 0.0f;
    f.A.z = vec.z - v88.z;
    f.B.x = vec.x - va4.x;
    f.B.z = vec.z - va4.z;
    f.Lb = (float)sqrt(f.B.x * f.B.x + f.B.z * f.B.z);
    f.B.FUN_0022d110();
    f.A.FUN_0022d110();
    float t = f11c + 5.0f;
    b60 = 0;
    if (t > f.Lb) {
        float v = f.Lb - 2.0f;
        f11c = (1.5f < v) ? v : 1.5f;
        b60 = 1;
    }
    v104.z = 0.0f;
    v104.y = 0.0f;
    v104.x = 0.0f;
    if (f.Lb > f120) {
        volatile float tx = f11c * vf8.x;
        volatile float ty = f11c * vf8.y;
        double z80 = f11c * vf8.z;
        v104.z = (float)(z80 + vec.z);
        v104.x = tx + vec.x;
        v104.y = ty + vec.y;
    } else {
        volatile float bx = f.B.x * f11c;
        volatile float by = f.B.y * f11c;
        double bz = f11c * f.B.z;
        v104.z = (float)(vec.z - bz);
        v104.x = vec.x - bx;
        v104.y = vec.y - by;
    }
    v110.x = v104.x - v88.x;
    v110.y = v104.y - v88.y;
    v110.z = v104.z - v88.z;
    v110.y = 0.0f;
    f.L2 = (float)sqrt(v110.x * v110.x + v110.y * v110.y + v110.z * v110.z);
    v110.FUN_0022d110();
    f.C.y = 0.0f;
    f.C.x = v104.x - vec.x;
    f.C.z = v104.z - vec.z;
    f.C.FUN_0022d110();
    f.E.x = f.C.z;
    f.E.z = -f.C.x;
    f.D.y = 0.0f;
    f.D.x = v104.x - va4.x;
    f.D.z = v104.z - va4.z;
    f.D.FUN_0022d110();
    FloatBits_101fe0 dp;
    dp.f = f.E.z * v110.z + f.E.x * v110.x + v110.y * 0.0f;
    dp.u &= 0x7fffffff;
    Vec3_101fe0 *edi;
    if (dp.f < 0.97 && f.L2 > 2.0f) {
        edi = &v144;
        v144 = v110;
        f180 = f.L2;
        FUN_0010ae50(a1, a2, 1.875f, edi, &f.O, 0, 0);
        if (f.L2 > 5.0f) {
            v144 = v110;
            f180 = f.L2;
        }
        f.E.x = 0.0f;
        f.E.y = 0.0f;
        f.E.z = 0.0f;
        if (v144.FUN_0022d2b0(&f.E, 1e-05f)) {
            if (f.C.z * v110.z + f.C.y * v110.y + f.C.x * v110.x > 0.0f) {
                v144 = f.C;
            } else {
                v144.z = -f.C.z;
                v144.x = -f.C.x;
                v144.y = -f.C.y;
            }
            f180 = -1.0f;
            FUN_0010ae50(a1, a2, 1.875f, edi, &f.O, 0, 0);
        }
    } else {
        FloatBits_101fe0 d3;
        d3.f = f.A.z * f.C.z + f.A.x * f.C.x + f.C.y * f.A.y;
        d3.u &= 0x7fffffff;
        if (d3.f < 0.97f) {
            float dot4 = f.E.z * v110.z + v110.y * 0.0f + f.E.x * v110.x;
            v144.y = 0.0f;
            if (dot4 > 0.0f) {
                v144.x = f.E.x;
                v144.z = f.E.z;
            } else {
                v144.x = -f.E.x;
                v144.z = -f.E.z;
            }
            f180 = -1.0f;
        }
        edi = &v144;
        FUN_0010ae50(a1, a2, 1.9499999f, edi, &f.O, 0, 0);
    }
    if (b60 != 0) {
        vd4 = vdc;
        edi->x = 0.0f;
        edi->y = 0.0f;
        edi->z = 0.0f;
        f.res = 0;
    } else if (f.Lb < f120 && fc8 < fe8 && f64 < 0.0f) {
        vd4 = vdc;
        edi->x = 0.0f;
        edi->y = 0.0f;
        edi->z = 0.0f;
        f.res = 0;
    }
    v144.y = 0.0f;
    edi->FUN_0022d110();
    return f.res;
}
