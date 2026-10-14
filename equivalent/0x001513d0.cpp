// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// hulkfight::motion::GroundSlideAction::vfunc_5 @ 0x001513d0
extern "C" double sqrt(double);
struct V3_1513d0 {
    float x, y, z;
    float FUN_0022d110();
};

struct Mat4_1513d0 {
    float m[16];
    void FUN_0022be40(const V3_1513d0 *pos);
};

struct Timing_1513d0 {
    char pad0[0x2064];
    V3_1513d0 fp2064;
    float f2070;
    float FUN_000354c0();
    char FUN_00035660(V3_1513d0 *out);
};

struct Clock_1513d0 {
    Timing_1513d0 *FUN_00059a30();
    char FUN_00059a50(V3_1513d0 *out);
};

struct Target_1513d0 {
    Clock_1513d0 *FUN_000592a0();
};

struct Config_1513d0 {
    char pad0[0x14];
    float angleOffset;     // 0x14
    float f18;
    float f1c;
    char pad20[4];
    float limit;           // 0x24
};

struct Driver {
    char pad0[0x18];
    Mat4_1513d0 xform;
};

extern float DAT_004afa08;
extern float DAT_004afa0c;
extern float DAT_004afa10;
void __cdecl FUN_00224d70(float angle, V3_1513d0 *v);

class GroundSlideAction {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual bool vfunc_5(int a, float dt);
    char pad04[0x1c - 4];
    Config_1513d0 *cfg;           // 0x1c
    Target_1513d0 *target;        // 0x20
    Driver *driver;        // 0x24
    float speed;           // 0x28
};

struct Frame_1513d0 {
    float speed;           // 0x10
    float t;               // 0x14
    float limit;           // 0x18
    V3_1513d0 d;                  // 0x1c
    V3_1513d0 e;                  // 0x28
    V3_1513d0 fwd;                // 0x34
    V3_1513d0 w;                  // 0x40
    V3_1513d0 o;                  // 0x4c
    V3_1513d0 r;                  // 0x58
};

bool GroundSlideAction::vfunc_5(int a, float dt)
{
    if (driver == 0)
        return false;
    Frame_1513d0 f;
    Clock_1513d0 *clock = target->FUN_000592a0();
    Timing_1513d0 *timing = clock->FUN_00059a30();
    f.fwd.x = DAT_004afa08;
    f.fwd.y = DAT_004afa0c;
    f.fwd.z = DAT_004afa10;
    f.limit = cfg->angleOffset;
    FUN_00224d70(timing->FUN_000354c0() - f.limit, &f.fwd);

    f.speed = speed;
    double x1 = f.fwd.x * f.speed;
    double y1 = f.fwd.y * f.speed;
    f.d.z = f.fwd.z * f.speed;
    f.limit = cfg->limit;
    double tt = f.speed * cfg->f18 * dt;
    f.t = tt;
    if (tt > f.speed) {
        f.d.x = 0.0f;
        f.d.y = 0.0f;
        f.d.z = 0.0f;
    } else {
        f.w = timing->fp2064;
        f.w.FUN_0022d110();
        double dot = f.fwd.z * f.w.z + f.fwd.y * f.w.y + f.fwd.x * f.w.x;
        double xt = f.fwd.x * f.t;
        double yt = f.fwd.y * f.t;
        volatile float zt = f.fwd.z * f.t;
        f.d.x = x1 - xt;
        f.d.y = y1 - yt;
        f.d.z = f.d.z - zt;
        double val;
        if (dot < -0.5f)
            val = (0.5f - (dot + 1.0f)) * 2.0 * timing->f2070 * cfg->f1c * dt;
        else
            val = 0.0f;
        if (f.t + val > f.speed) {
            f.d.x = 0.0f;
            f.d.y = 0.0f;
            f.d.z = 0.0f;
        } else {
            f.d.x = f.d.x - f.fwd.x * val;
            f.d.y = f.d.y - f.fwd.y * val;
            f.d.z = f.d.z - f.fwd.z * val;
        }
    }
    f.e.x = f.d.x * dt;
    f.e.y = f.d.y * dt;
    f.e.z = f.d.z * dt;
    f.o.x = 0.0f;
    f.o.y = 0.0f;
    f.o.z = 0.0f;
    clock->FUN_00059a50(&f.o);
    f.e.x = f.o.x + f.e.x;
    f.e.y = f.o.y + f.e.y;
    f.e.z = f.o.z + f.e.z;
    driver->xform.FUN_0022be40(&f.e);
    if (f.limit < 0.0f)
        return true;
    speed = sqrt(f.d.z * f.d.z + f.d.y * f.d.y + f.d.x * f.d.x);
    timing->FUN_00035660(&f.r);
    float len = sqrt(f.r.z * f.r.z + f.r.y * f.r.y + f.r.x * f.r.x);
    if (len < speed)
        speed = len;
    return speed > f.limit;
}
