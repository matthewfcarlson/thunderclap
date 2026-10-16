// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// hulkfight::motion::BallAndChainReturnAction::vfunc_5 @ 0x00182740
// hulkfight::motion::BallAndChainReturnAction::vfunc_5 @ 0x00182740
#include "decls/address.h"
struct V3_182740 {
    float x, y, z;
    float FUN_0022d110();
    bool FUN_0022d2b0(const V3_182740 *other, float eps);
};

struct Mat_182740 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022c120();
    void FUN_0022c2b0(V3_182740 *in, V3_182740 *out);
    void FUN_0022ca90(Mat_182740 *a, Mat_182740 *b);
};

class Obj_182740 {
public:
    virtual void AddRef();
    virtual void Release();
};

class Weapon_182740 {
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
    virtual Mat_182740 *v15();
};

struct Xform_182740 {
    Mat_182740 *FUN_00221c40();
};

struct Skeleton_182740 {
    char pad0[0x10];
    Xform_182740 xform;
};

struct Table_182740 {
    char pad0[0x1c];
    Mat_182740 *xforms;     // 0x1c
    unsigned FUN_002843a0(unsigned lo, unsigned hi);
};

struct Holder_182740 {
    char pad0[0x120];
    Table_182740 *table;    // 0x120
    char pad124[0x328 - 0x124];
    Obj_182740 *held;       // 0x328
    Weapon_182740 *FUN_00035ef0(unsigned slot);
    void FUN_0003acf0(unsigned id, Weapon_182740 *w, int a, int b, int c, Mat_182740 *m);
};

struct Owner_182740 {
    Holder_182740 *FUN_00059a30();
    Skeleton_182740 *FUN_00059a40();
};

struct Source_182740 {
    Owner_182740 *FUN_000592a0();
};

struct Config_182740 {
    char pad0[0x14];
    unsigned slot;          // 0x14
    char pad18[4];
    float f1c;              // 0x1c
    float f20;              // 0x20
    float f24;              // 0x24
    float f28;              // 0x28
    V3_182740 v2c;          // 0x2c
    V3_182740 v38;          // 0x38
    char pad44[4];
    char f48[8];            // 0x48
    V3_182740 v50;          // 0x50
    char pad5c[4];
    unsigned f60;           // 0x60
    unsigned f64;           // 0x64
    V3_182740 v68;          // 0x68
};

struct Ray_182740 {
    bool FUN_00201e00(V3_182740 *a, V3_182740 *b, int c, V3_182740 *d, V3_182740 *e, int f, int g);
};

struct World {
    char pad0[0x24];
    Ray_182740 *ray;        // 0x24
};

struct Decal_182740 {
    unsigned FUN_00283ca0(void *a, V3_182740 *b, V3_182740 *c, float d);
    void FUN_00283450(unsigned h, V3_182740 *b, V3_182740 *c, float d);
};
Decal_182740 *FUN_0027f250();

extern "C" void __cdecl FUN_00224db0(Mat_182740 *m, V3_182740 *up, V3_182740 *fwd);
int __cdecl FUN_00098190(float dt, float f3c, float f20, int zero0, Obj_182740 *held, float f24, V3_182740 *pos, V3_182740 *dir, int z1, int z2, int z3, int one);
extern "C" void *memcpy(void *d, const void *s, unsigned int n);

struct Frame_182740 {
    V3_182740 Q;            // 0x10
    char pad1c[3];
    bool flag;              // 0x1f
    V3_182740 P;            // 0x20
    V3_182740 d;            // 0x2c
    V3_182740 in;           // 0x38
    V3_182740 D2;           // 0x44
    Weapon_182740 *weapon;  // 0x50
    float nL;               // 0x54
    Holder_182740 *holder;  // 0x58
    unsigned slot;          // 0x5c
    Owner_182740 *owner;    // 0x60
    V3_182740 end;          // 0x64
    V3_182740 nd;           // 0x70
    V3_182740 start;        // 0x7c
    Mat_182740 rot;         // 0x88
    V3_182740 hitB;         // 0xc8
    V3_182740 hitA;         // 0xd4
    Mat_182740 wmat;        // 0xe0
    Mat_182740 inv;         // 0x120
};

namespace hulkfight { namespace motion {

class BallAndChainReturnAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int state, float dt);
    char pad04[0x1c - 4];
    Config_182740 *cfg;     // 0x1c
    Source_182740 *source;  // 0x20
    V3_182740 pos;          // 0x24
    V3_182740 dir;          // 0x30
    float speed;            // 0x3c
    float dist;             // 0x40
    unsigned decal;         // 0x44
};

bool BallAndChainReturnAction::vfunc_5(int state, float dt)
{
    if (state != 1)
        return true;
    if (source == 0)
        return false;

    Frame_182740 f;
    f.owner = source->FUN_000592a0();
    f.holder = f.owner->FUN_00059a30();
    f.slot = cfg->slot;
    f.weapon = f.holder->FUN_00035ef0(f.slot);
    f.in = cfg->v2c;
    f.owner->FUN_00059a40()->xform.FUN_00221c40()->FUN_0022c2b0(&f.in, &f.P);

    f.d = f.P;
    f.d.x = f.d.x - pos.x;
    f.d.y = f.d.y - pos.y;
    f.d.z = f.d.z - pos.z;
    f.d.FUN_0022d110();

    speed = dt * cfg->f1c + speed;
    dist = dist - speed * dt;
    if (f.holder->held != 0)
        FUN_00098190(dt, speed, cfg->f20, 0, f.holder->held, cfg->f24, &pos, &dir, 0, 0, 0, 1);

    float s = dt * speed;
    f.Q.x = dir.x * s + pos.x;
    volatile float qy = dir.y * s;
    volatile float qz = dir.z * s;
    f.Q.y = qy + pos.y;
    f.Q.z = qz + pos.z;
    f.D2.x = f.Q.x - f.P.x;
    f.D2.y = f.Q.y - f.P.y;
    f.D2.z = f.Q.z - f.P.z;
    f.D2.FUN_0022d110();

    float L = dist;
    f.Q.x = f.P.x + f.D2.x * L;
    volatile float my = f.D2.y * L;
    volatile float mz = f.D2.z * L;
    f.Q.y = f.P.y + my;
    f.Q.z = f.P.z + mz;

    if (DAT_004dd700->ray->FUN_00201e00(&f.P, &f.Q, 1, &f.hitA, &f.hitB, 0, 0)) {
        dir = f.d;
        f.nL = -dist;
        volatile float hx = f.nL * dir.x;
        f.Q.x = f.P.x + hx;
        f.Q.y = f.P.y + dir.y * f.nL;
        f.Q.z = f.P.z + dir.z * f.nL;
    }

    f.flag = true;
    if (dist <= cfg->f28) {
        f.flag = false;
        f.Q = f.P;
    } else {
        f.d.x = f.P.x - f.Q.x;
        f.d.y = f.P.y - f.Q.y;
        f.d.z = f.P.z - f.Q.z;
        f.d.FUN_0022d110();
    }

    if (f.weapon != 0) {
        memcpy(&f.wmat, f.weapon->v15(), sizeof(Mat_182740));
        f.in = cfg->v50;
        f.wmat.FUN_0022c2b0(&f.in, &f.end);
    } else {
        f.end = pos;
    }

    Table_182740 *table = f.holder->table;
    unsigned idx = table->FUN_002843a0(cfg->f60, cfg->f64);
    if (idx == 0xffff)
        idx = 0;
    f.in = cfg->v68;
    table->xforms[idx].FUN_0022c2b0(&f.in, &f.start);

    Decal_182740 *dm = FUN_0027f250();
    if (decal == 0)
        decal = dm->FUN_00283ca0(&cfg->f48, &f.end, &f.start, 1000.0f);
    else
        dm->FUN_00283450(decal, &f.end, &f.start, 1000.0f);

    if (f.weapon != 0) {
        memcpy(&f.inv, f.owner->FUN_00059a40()->xform.FUN_00221c40(), sizeof(Mat_182740));
        f.inv.FUN_0022c120();
        f.rot.FUN_0022b980();
        f.in = cfg->v38;
        f.nd.x = -f.d.x;
        f.nd.y = -f.d.y;
        f.nd.z = -f.d.z;
        if (!f.in.FUN_0022d2b0(&f.nd, 9.99999974737875e-06f))
            FUN_00224db0(&f.rot, &f.in, &f.nd);
        f.rot.m[12] = f.Q.x;
        f.rot.m[13] = f.Q.y;
        f.rot.m[14] = f.Q.z;
        pos = f.Q;
        f.wmat.FUN_0022b980();
        f.wmat.FUN_0022ca90(&f.rot, &f.inv);
        f.holder->FUN_0003acf0(f.slot, f.weapon, 0, 0, 0, &f.wmat);
    }
    return f.flag;
}

} }
