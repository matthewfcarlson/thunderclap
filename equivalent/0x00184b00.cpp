// STATUS: equivalent (tools/equiv.py level 3: 3038 inputs, branch coverage 32/32)
// hulkfight::motion::BallAndChainShootAction::vfunc_5 @ 0x00184b00
// hulkfight::motion::BallAndChainShootAction::vfunc_5 @ 0x00184b00
#include "decls/address.h"
#include "decls/data/game/global.h"
struct V3_184b00 {
    float x, y, z;
    bool FUN_0022d2b0(const V3_184b00 *other, float eps);
};

struct Mat_184b00 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022c120();
    void FUN_0022c2b0(V3_184b00 *in, V3_184b00 *out);
    void FUN_0022ca90(Mat_184b00 *a, Mat_184b00 *b);
};

class Obj_184b00 {
public:
    virtual void AddRef();
    virtual void Release();
};

class Weapon_184b00 {
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
    virtual Mat_184b00 *v15();
    unsigned FUN_001d72e0();
    void FUN_001d8100();
};

struct Xform_184b00 {
    Mat_184b00 *FUN_00221c40();
};

struct Skeleton_184b00 {
    char pad0[0x10];
    Xform_184b00 xform;
};

struct Table_184b00 {
    char pad0[0x1c];
    Mat_184b00 *xforms;     // 0x1c
    unsigned FUN_002843a0(unsigned lo, unsigned hi);
};

struct Holder_184b00 {
    char pad0[0x120];
    Table_184b00 *table;    // 0x120
    Weapon_184b00 *FUN_00035ef0(unsigned slot);
    void FUN_0003acf0(unsigned id, Weapon_184b00 *w, int a, int b, int c, Mat_184b00 *m);
};

struct Owner_184b00 {
    Holder_184b00 *FUN_00059a30();
    Skeleton_184b00 *FUN_00059a40();
};

struct Source_184b00 {
    Owner_184b00 *FUN_000592a0();
};

struct Config_184b00 {
    char pad0[0x14];
    unsigned slot;          // 0x14
    char pad18[0x30 - 0x18];
    V3_184b00 v30;          // 0x30
    char pad3c[0x58 - 0x3c];
    unsigned f58;           // 0x58
    char pad5c[0x60 - 0x5c];
    char f60[8];            // 0x60
    V3_184b00 v68;          // 0x68
    char pad74[0x78 - 0x74];
    unsigned f78;           // 0x78
    unsigned f7c;           // 0x7c
    V3_184b00 v80;          // 0x80
    unsigned f8c;           // 0x8c
    unsigned f90;           // 0x90
};

struct Ray_184b00 {
    bool FUN_00201e00(V3_184b00 *a, V3_184b00 *b, int c, V3_184b00 *d, V3_184b00 *e, int *o1, int *o2);
};

struct Spawn_184b00 {
    void FUN_001f6cd0(int a, int b, V3_184b00 *hitA, V3_184b00 *hitB, V3_184b00 *dir, int c, unsigned d, unsigned e, int *out, int z);
};

struct Sink_184b00 {
    void FUN_001ecd00(int v, Holder_184b00 *h);
};

struct Player_184b00 {
    void FUN_00029bb0(unsigned a, Obj_184b00 *b, float c);
};

struct World {
    char pad0[0x20];
    Player_184b00 *player;  // 0x20
    Ray_184b00 *ray;        // 0x24
    char pad28[0x34 - 0x28];
    Sink_184b00 *sink;      // 0x34
    Spawn_184b00 *spawn;    // 0x38
};

struct Decal_184b00 {
    unsigned FUN_00283ca0(void *a, V3_184b00 *b, V3_184b00 *c, float d);
    void FUN_00283450(unsigned h, V3_184b00 *b, V3_184b00 *c, float d);
};
Decal_184b00 *FUN_0027f250();

extern "C" void __cdecl FUN_00224db0(Mat_184b00 *m, V3_184b00 *up, V3_184b00 *fwd);
int __cdecl FUN_00098190(float dt, float f44, float f48, int zero0, Obj_184b00 *attached, unsigned f58, V3_184b00 *pos, V3_184b00 *dir, int z1, int z2, int z3, int one);
extern "C" void *memcpy(void *d, const void *s, unsigned int n);

struct Frame_184b00 {
    char pad10[3];
    bool hit;               // 0x13
    union { float t; int outv; };   // 0x14
    V3_184b00 in;           // 0x18
    Weapon_184b00 *weapon;  // 0x24
    unsigned sp28;          // 0x28
    int obj;                // 0x2c
    int objb;               // 0x30
    Holder_184b00 *holder;  // 0x34
    unsigned slot;          // 0x38
    Owner_184b00 *owner;    // 0x3c
    V3_184b00 end;          // 0x40
    V3_184b00 start;        // 0x4c
    V3_184b00 hitA;         // 0x58
    V3_184b00 hitB;         // 0x64
    Mat_184b00 rot;         // 0x70
    Mat_184b00 wmat;        // 0xb0
    Mat_184b00 inv;         // 0xf0
};

namespace hulkfight { namespace motion {

class BallAndChainShootAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int state, float dt);
    char pad04[0x1c - 4];
    Config_184b00 *cfg;     // 0x1c
    Source_184b00 *source;  // 0x20
    Obj_184b00 *attached;   // 0x24
    V3_184b00 pos;          // 0x28
    V3_184b00 dir;          // 0x34
    float timeLeft;         // 0x40
    float speed;            // 0x44
    float f48;              // 0x48
    char pad4c[4];
    unsigned decal;         // 0x50
};

bool BallAndChainShootAction::vfunc_5(int state, float dt)
{
    if (state != 1)
        return true;
    if (source == 0)
        return false;

    Frame_184b00 f;
    f.owner = source->FUN_000592a0();
    f.holder = f.owner->FUN_00059a30();
    f.slot = cfg->slot;
    f.weapon = f.holder->FUN_00035ef0(f.slot);
    f.t = dt * speed;
    timeLeft = timeLeft - f.t;

    if (attached != 0) {
        f.sp28 = cfg->f58;
        if (FUN_00098190(dt, speed, f48, 0, attached, f.sp28, &pos, &dir, 0, 0, 0, 1) != 0) {
            if (f.weapon != 0) {
                Player_184b00 *player = DAT_004dd700->player;
                player->FUN_00029bb0(f.weapon->FUN_001d72e0(), attached, timeLeft);
            }
        } else {
            if (f.weapon != 0)
                f.weapon->FUN_001d8100();
            if (attached != 0) {
                attached->Release();
                attached = 0;
            }
        }
    }

    pos.x = f.t * dir.x + pos.x;
    pos.y = f.t * dir.y + pos.y;
    pos.z = f.t * dir.z + pos.z;

    Table_184b00 *table = f.holder->table;
    unsigned idx = table->FUN_002843a0(cfg->f78, cfg->f7c);
    if (idx == 0xffff)
        idx = 0;
    f.in = cfg->v80;
    table->xforms[idx].FUN_0022c2b0(&f.in, &f.start);

    f.hit = false;
    f.obj = 0;
    f.objb = 0;
    if (DAT_004dd700->ray->FUN_00201e00(&f.start, &pos, 1, &f.hitB, &f.hitA, &f.obj, &f.objb)) {
        f.hit = true;
        if (f.obj != 0) {
            f.sp28 = cfg->f90;
            f.t = 0;
            DAT_004dd700->spawn->FUN_001f6cd0(f.obj, f.objb, &f.hitB, &f.hitA, &dir, cfg->f8c - 1, f.sp28, f.sp28, &f.outv, 0);
            DAT_004dd700->sink->FUN_001ecd00(f.outv, f.holder);
        }
    }

    if (f.weapon != 0) {
        memcpy(&f.wmat, f.weapon->v15(), sizeof(Mat_184b00));
        f.in = cfg->v68;
        f.wmat.FUN_0022c2b0(&f.in, &f.end);
    } else {
        f.end = pos;
    }

    Decal_184b00 *dm = FUN_0027f250();
    if (decal == 0)
        decal = dm->FUN_00283ca0(&cfg->f60, &f.end, &f.start, 1000.0f);
    else
        dm->FUN_00283450(decal, &f.end, &f.start, 1000.0f);

    if (f.weapon != 0) {
        memcpy(&f.inv, f.owner->FUN_00059a40()->xform.FUN_00221c40(), sizeof(Mat_184b00));
        f.inv.FUN_0022c120();
        f.rot.FUN_0022b980();
        f.in = cfg->v30;
        if (!f.in.FUN_0022d2b0(&dir, 9.99999974737875e-06f))
            FUN_00224db0(&f.rot, &f.in, &dir);
        f.rot.m[12] = pos.x;
        f.rot.m[13] = pos.y;
        f.rot.m[14] = pos.z;
        f.wmat.FUN_0022b980();
        f.wmat.FUN_0022ca90(&f.rot, &f.inv);
        f.holder->FUN_0003acf0(f.slot, f.weapon, 0, 0, 0, &f.wmat);
    }

    if (!f.hit && timeLeft > (*(float*)&DAT_003f32e0))
        return true;
    return false;
}

} }
