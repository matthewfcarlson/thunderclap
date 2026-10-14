// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// CJumpAction::vfunc_7 @ 0x00018d40
extern "C" double sqrt(double);

struct V3_18d40 {
    float x, y, z;
    float FUN_0022d110();
};

struct Mat4_18d40 {
    float m[16];
    void FUN_0022be40(const V3_18d40 *pos);
    void FUN_00221d20(float angle);
};

struct Timing_18d40 {
    char pad0[0x2064];
    V3_18d40 fp2064;
    float f2070;
    void FUN_000359c0(int v);
    float FUN_000354c0();
    void FUN_000357a0(V3_18d40 *v);
};

struct Clock_18d40 {
    Timing_18d40 *FUN_00059a30();
    char FUN_00059a50(V3_18d40 *out);
};

struct Target_18d40 {
    Clock_18d40 *FUN_000592a0();
};

class Character_18d40 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual float v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual char v30();
    float FUN_00069370(float v);
};

struct Driver {
    char pad0[0x18];
    Mat4_18d40 xform;
};

extern float DAT_0048e054;
extern float DAT_0048e058;
extern float DAT_0048e05c;
float __cdecl FUN_00224f10(V3_18d40 *v);
float __cdecl FUN_00224fc0(float a, float b);
void __cdecl FUN_00224d70(float angle, V3_18d40 *v);

union Bits_18d40 {
    float f;
    unsigned int u;
};

class CJumpAction {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual bool vfunc_7(float dt);
    virtual void f8();
    char pad04[0x1c - 4];
    Target_18d40 *target;        // 0x1c
    Character_18d40 *chara;      // 0x20
    Driver *driver;        // 0x24
    float f28;
    float f2c;
    float f30;
    char pad34[4];
    float f38;
};

struct Frame_18d40 {
    char pad0[4];
    float ang;             // 0xc
    Bits_18d40 ad;               // 0x10
    float ang2;            // 0x14
    float tmp;             // 0x18
    V3_18d40 r;                  // 0x1c
    V3_18d40 q;                  // 0x28
    V3_18d40 p;                  // 0x34
    V3_18d40 w;                  // 0x40
    V3_18d40 fwd;                // 0x4c
    V3_18d40 pos0;               // 0x58
};

bool CJumpAction::vfunc_7(float dt)
{
    if (driver == 0)
        return false;
    Frame_18d40 f;
    Clock_18d40 *clock = target->FUN_000592a0();
    Timing_18d40 *timing = clock->FUN_00059a30();
    timing->FUN_000359c0(3);
    f.pos0.x = 0.0f;
    f.pos0.y = 0.0f;
    f.pos0.z = 0.0f;
    clock->FUN_00059a50(&f.pos0);
    f.w = timing->fp2064;
    f.w.y = 0.0f;
    f.w.FUN_0022d110();
    f28 = f28 - dt * f30;
    f.ang = timing->FUN_000354c0();
    if (timing->f2070 > 0.0f) {
        f.ang2 = FUN_00224f10(&f.w);
        f.ad.f = FUN_00224fc0(f.ang, f.ang2);
        f.ad.u &= 0x7fffffff;
        bool skip = false;
        if (!(f.ad.f < 2.3561945f)) {
            if (!(f2c <= 5.0f))
                skip = true;
        }
        if (!skip) {
            f.tmp = chara->FUN_00069370(f2c);
            if (f.tmp < 0.0f) {
                f.ang = f.ang2;
            } else {
                float d2 = FUN_00224fc0(f.ang, f.ang2);
                f.tmp = f.tmp * dt;
                f.ad.f = d2;
                f.ad.u &= 0x7fffffff;
                if (f.ad.f <= f.tmp) {
                    f.ang = f.ang2;
                } else if (!(d2 < 0.0f)) {
                    f.ang = f.tmp + f.ang;
                } else {
                    f.ang = f.ang - f.tmp;
                }
            }
        }
    }
    driver->xform.FUN_00221d20(f.ang);
    f.tmp = chara->v21();
    f.fwd.x = DAT_0048e054;
    f.fwd.y = DAT_0048e058;
    f.fwd.z = DAT_0048e05c;
    FUN_00224d70(f.ang, &f.fwd);
    float t = f.fwd.z * f.w.z + f.fwd.x * f.w.x + f.fwd.y * f.w.y;
    t = t * f.tmp;
    f.tmp = -f2c;
    if (t < f.tmp)
        t = f.tmp;
    t = t * dt;
    f.q.x = DAT_0048e054;
    f.q.y = DAT_0048e058;
    f.q.z = DAT_0048e05c;
    f.q.x = f.q.x * t;
    f.q.y = f.q.y * t;
    f.q.z = f.q.z * t;
    FUN_00224d70(f.ang, &f.q);
    timing->FUN_000357a0(&f.q);
    float u = dt * f2c;
    f.r.x = DAT_0048e054;
    f.r.z = DAT_0048e05c;
    f.r.y = DAT_0048e058;
    f.r.x = f.r.x * u;
    f.r.z = f.r.z * u;
    f.r.y = dt * f28;
    FUN_00224d70(f.ang, &f.r);
    f.p = f.pos0;
    f.p.x = f.p.x + f.r.x;
    f.p.y = f.p.y + f.r.y;
    f.p.z = f.p.z + f.r.z;
    driver->xform.FUN_0022be40(&f.p);
    f38 = f38 - (float)sqrt(f.r.z * f.r.z + f.r.x * f.r.x + f.r.y * f.r.y);
    if (f28 < 0.0f) {
        if (chara->v30())
            return false;
    }
    return true;
}
