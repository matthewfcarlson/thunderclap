// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 56/56)
// hulkfight::motion::WallJumpAction::vfunc_3 @ 0x00140650
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "decls/address.h"
extern "C" double __cdecl sqrt(double);
extern "C" double __cdecl sin(double);

struct V3_140650 {
    float x, y, z;
    float FUN_0022d110();
    char FUN_0022d2b0(const V3_140650 *other, float eps);
};

struct Mat4_140650 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(V3_140650 *axis, float angle);
    void FUN_0022c3b0(V3_140650 *in, V3_140650 *out);
};

struct NameHolder_140650 {
    char pad[8];
    void FUN_0027b040(const char *name);
};

class JointDriver {
public:
    virtual void AddRef();
    char pad04[4];
    NameHolder_140650 name;
    char pad10[0x70 - 0x10];
    JointDriver *FUN_002248f0(int a);
};

struct Rig_140650 {
    void FUN_00222890(JointDriver *d, float a, int b, float c, int e, int f, float g);
};

struct Gear_140650 {
    char pad00[0x34];
    float f34;
};

struct Pos_140650 {
    void FUN_00059a50(V3_140650 *out);
};

struct Stats_140650 {
    char pad00[0x10];
    Pos_140650 *f10;
    char pad14[0x11c - 0x14];
    Gear_140650 *f11c;
    char pad120[0x140 - 0x120];
    int f140;
    char pad144[0x1ad4 - 0x144];
    V3_140650 v1ad4;
    V3_140650 v1ae0;
    V3_140650 v1aec;
    V3_140650 v1af8;
    char pad1b04[0x2064 - 0x1b04];
    V3_140650 v2064;
    void FUN_00035550(V3_140650 *out);
    float FUN_000354c0();
    char FUN_000356c0(V3_140650 *out);
    float FUN_0003ec00(int a);
};

struct Anchor_140650 {
    void FUN_00059a50(V3_140650 *out);
};
Anchor_140650 *__fastcall FUN_000592a0(void *owner);
Stats_140650 *__fastcall FUN_00059a30(Anchor_140650 *f);
Rig_140650 *__fastcall FUN_00059a40(Anchor_140650 *f);

struct Fx34_140650 {
    void FUN_001ec980(Stats_140650 *st, const char *name);
};
struct World8 {
    void FUN_00099d20(struct World *w, Stats_140650 *st, float len, float y, int z);
};
struct World {
    char pad00[8];
    World8 *f8;
    char pad0c[0x34 - 0xc];
    Fx34_140650 *f34;
};
extern float DAT_004ad77c;
extern float DAT_004ad780;
extern float DAT_004ad784;

void *thunk_FUN_0008d690(unsigned int size);
float __cdecl FUN_00018a20(float v);
void __cdecl FUN_00224d70(float angle, V3_140650 *axis);

struct Data_140650 {
    char pad00[0x14];
    float f14;
    float f18;
    float f1c;
    int f20;
    float f24;
    float f28;
    char pad2c[4];
    float f30;
    char pad34[4];
    char b38;
    char pad39[3];
    float f3c;
    float f40;
    float f44;
    int f48;
    int f4c;
    int f50;
};

struct Frame_140650 {
    V3_140650 t10;                 // 0x10
    float f1c;              // 0x1c
    V3_140650 w;                   // 0x20
    V3_140650 bq;                  // 0x2c
    float s38;              // 0x38
    V3_140650 av;                  // 0x3c
    V3_140650 rv;                  // 0x48
    V3_140650 pv;                  // 0x54
    float ang;              // 0x60
    float spd;              // 0x64
    Anchor_140650 *saved;          // 0x68
    V3_140650 qv;                  // 0x6c
    Mat4_140650 m;                 // 0x78
    V3_140650 out;                 // 0xb8
};

class WallJumpAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x1c - 4];
    Data_140650 *data;
    void *owner;
    JointDriver *driver;
    V3_140650 v28;
    V3_140650 dir;                 // 0x34
    char b40;
    char pad41[3];
    V3_140650 v44;
};

bool WallJumpAction::vfunc_3(int a, int b)
{
    Frame_140650 f;
    Anchor_140650 *fighter = FUN_000592a0(owner);
    f.saved = fighter;
    Stats_140650 *st = FUN_00059a30(fighter);
    bool cond = (st->f140 == 4);
    b40 = cond;
    if (cond) {
        dir = st->v1af8;
        v28 = st->v1aec;
        f.t10.x = 0;
        f.t10.y = 0;
        f.t10.z = 0;
        if (dir.FUN_0022d2b0(&f.t10, 1e-05f)) {
            dir = st->v1ae0;
            v28 = st->v1ad4;
            f.t10.x = 0;
            f.t10.y = 0;
            f.t10.z = 0;
            if (dir.FUN_0022d2b0(&f.t10, 1e-05f)) {
                f.t10.x = 0;
                f.t10.y = 0;
                f.t10.z = -1.0f;
                st->FUN_00035550(&f.t10);
                dir = f.t10;
                dir.x = -dir.x;
                dir.z = -dir.z;
                f.f1c = st->f11c->f34;
                f.bq.x = 0;
                f.bq.y = 0;
                f.bq.z = 0;
                fighter->FUN_00059a50(&f.bq);
                v28 = f.t10;
                v28.x = f.f1c * v28.x;
                v28.y = f.f1c * v28.y;
                v28.z = f.f1c * v28.z;
                v28.x = f.bq.x + v28.x;
                v28.y = f.bq.y + v28.y;
                v28.z = f.bq.z + v28.z;
            }
        }
        dir.y = 0;
        dir.FUN_0022d110();
    } else {
        dir.x = DAT_004ad77c;
        dir.y = DAT_004ad780;
        dir.z = DAT_004ad784;
        FUN_00224d70(st->FUN_000354c0() + 3.14159274f, &dir);
    }

    f.s38 = 0;
    if (data->b38) {
        if (!st->FUN_000356c0(&f.w))
            return false;
        float dot = f.w.y * dir.y + f.w.z * dir.z + f.w.x * dir.x;
        f.bq = dir;
        f.t10.x = 0;
        f.t10.y = 0;
        f.t10.z = -1.0f;
        dot = -dot;
        f.bq.y = f.bq.y * dot;
        f.bq.z = f.bq.z * dot;
        f.w.x = f.bq.x * dot + f.w.x;
        f.w.y = f.bq.y + f.w.y;
        f.w.z = f.bq.z + f.w.z;
        st->FUN_00035550(&f.t10);
        f.t10.y = 0;
        f.t10.FUN_0022d110();
        float dot2 = f.t10.z * f.w.z + f.w.y * f.t10.y + f.t10.x * f.w.x;
        dot2 = -dot2;
        f.bq.y = dot2 * f.t10.y;
        f.bq.z = f.t10.z * dot2;
        f.w.x = f.t10.x * dot2 + f.w.x;
        f.w.y = f.bq.y + f.w.y;
        f.w.z = f.bq.z + f.w.z;
        if (f.w.y < 0.0f) {
            if (b40)
                f.w.y = 0;
            else
                f.w = f.t10;
        }
        f.s38 = f.w.FUN_0022d110();
        if (f.s38 <= 0.0f) {
            f.w.x = 0;
            f.w.y = 1.0f;
            f.w.z = 0;
        }
    } else {
        f.t10.x = 0;
        f.t10.y = 1.0f;
        f.t10.z = 0;
        f.m.FUN_0022b980();
        f.m.FUN_0022baf0(&dir, data->f3c);
        f.m.FUN_0022c3b0(&f.t10, &f.w);
    }
    f.rv = f.w;

    if (!data->b38) {
        f.f1c = data->f40 * 0.5f;
        f.m.FUN_0022b980();
        f.m.FUN_0022baf0(&dir, 1.57079637f - data->f44);
        f.qv.x = 0;
        f.qv.y = 1.0f;
        f.qv.z = 0;
        f.m.FUN_0022c3b0(&f.qv, &f.av);
        f.m.FUN_0022baf0(&dir, -f.f1c);
        f.m.FUN_0022c3b0(&f.w, &f.bq);
        if (f.bq.y < f.av.y) {
            if (f.bq.z * f.av.z + f.bq.x * f.av.x + f.av.y * f.bq.y > 0.0f) {
                f.bq = f.av;
            } else {
                f.bq.x = -f.av.x;
                f.bq.y = f.av.y;
                f.bq.z = -f.av.z;
            }
        }
        f.m.FUN_0022baf0(&dir, f.f1c);
        f.m.FUN_0022c3b0(&f.w, &f.t10);
        if (f.t10.y < f.av.y) {
            if (f.t10.z * f.av.z + f.t10.x * f.av.x + f.t10.y * f.av.y > 0.0f) {
                f.t10 = f.av;
            } else {
                f.t10.x = -f.av.x;
                f.t10.y = f.av.y;
                f.t10.z = -f.av.z;
            }
        }
        f.pv = st->v2064;
        float dp = f.pv.z * dir.z + f.pv.y * dir.y + f.pv.x * dir.x;
        f.av = dir;
        dp = -dp;
        f.av.y = f.av.y * dp;
        f.av.z = f.av.z * dp;
        f.pv.x = f.av.x * dp + f.pv.x;
        f.pv.y = f.av.y + f.pv.y;
        f.pv.z = f.av.z + f.pv.z;
        f.pv.FUN_0022d110();
        if (FUN_00018a20(f.pv.y * f.w.y + f.pv.z * f.w.z + f.pv.x * f.w.x) < f.f1c) {
            f.rv = f.pv;
        } else {
            if ((f.pv.y * f.t10.y + f.pv.z * f.t10.z + f.pv.x * f.t10.x)
                < (f.pv.y * f.bq.y + f.pv.z * f.bq.z + f.pv.x * f.bq.x))
                f.rv = f.bq;
            else
                f.rv = f.t10;
        }
    }

    Data_140650 *d = data;
    if (FUN_00018a20(f.rv.y) < d->f30 * 0.5f) {
        f.rv.x = 0;
        f.rv.y = 1.0f;
        f.rv.z = 0;
    }
    f.qv.x = dir.z - dir.y * 0.0f;
    f.qv.y = dir.x * 0.0f - dir.z * 0.0f;
    f.qv.z = dir.y * 0.0f - dir.x;
    float t = (f.w.y < 0.0f) ? 0.0f : f.w.y;
    f.ang = d->f24 + (d->f28 - d->f24) * t;
    f.m.FUN_0022b980();
    f.m.FUN_0022baf0(&f.qv, f.ang);
    f.t10 = f.rv;
    f.m.FUN_0022c3b0(&f.t10, &f.rv);
    f.ang = st->FUN_0003ec00(0);
    Data_140650 *d2 = data;
    float lo = d2->f14;
    if (lo < f.s38)
        lo = f.s38;
    float hi = d2->f18;
    if (hi < lo)
        hi = lo;
    f.s38 = lo + (hi - lo) * f.ang;
    if (f.rv.y < 0.0f) {
        if (f.rv.y > -1e-05f)
            f.rv.y = 0;
    }
    v44 = f.rv;
    v44.x = f.s38 * v44.x;
    v44.y = f.s38 * v44.y;
    v44.z = f.s38 * v44.z;

    f.f1c = data->f1c;
    if (f.f1c > 0.0f) {
        float vx = *(volatile float *)&v44.x;
        float vz = *(volatile float *)&v44.z;
        double sp = sqrt(vx * vx + vz * vz);
        f.spd = (float)sp;
        if (sp > f.f1c) {
            v44.y = (float)(sin(FUN_00018a20(f.f1c / f.s38)) * f.s38);
            v44.x = (f.f1c / f.spd) * v44.x;
            v44.z = (f.f1c / f.spd) * v44.z;
        }
    }

    Rig_140650 *rig = FUN_00059a40(f.saved);
    if (!rig)
        return false;
    Data_140650 *dd = data;
    int e4c = dd->f4c;
    int e50 = dd->f50;
    int e48 = dd->f48;
    void *mem = thunk_FUN_0008d690(0x70);
    JointDriver *drv;
    if (mem)
        drv = ((JointDriver *)mem)->FUN_002248f0(0);
    else
        drv = 0;
    driver = drv;
    drv->name.FUN_0027b040("wallJump");
    driver->AddRef();
    rig->FUN_00222890(driver, -1.0f, e48, 1.0f, e4c, e50, -1.0f);
    World *world = DAT_004dd700;
    float hx = *(volatile float *)&v44.x;
    float hz = *(volatile float *)&v44.z;
    float hl = (float)sqrt(hx * hx + hz * hz);
    world->f8->FUN_00099d20(world, st, hl, v44.y, data->f20);
    st->f10->FUN_00059a50(&f.out);
    if (f.ang >= 1.0f) {
        if (f.out.y > 100.0f)
            world->f34->FUN_001ec980(st, "StartChargedJump");
    }
    return true;
}
