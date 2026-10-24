// STATUS: equivalent (tools/equiv.py level 3: 3037 inputs, branch coverage 18/18; Wine build 3036 inputs, 18/18)
// hulkfight::motion::HitFloatAction::vfunc_5 @ 0x0014fad0
#include "decls/data/game/global.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"

struct V3_14fad0 {
    float x, y, z;
    bool FUN_0022d2b0(const V3_14fad0 *other, float eps);
    float FUN_0022d110();
};

struct Transform_14fad0 {
    void FUN_0022be40(const V3_14fad0 *pos);
};

class FloatObject_14fad0 {
public:
    virtual void vfunc_0();
    char pad04[0x18 - 4];
    Transform_14fad0 transform;
};

struct Target_14fad0 {
    char pad0[0x28];
    V3_14fad0 size;
    char pad34[0x5c - 0x34];
    float limit;
};

struct PlayerCfg {
    char pad0[0x2c];
    float f2c;
    char pad30[4];
    float f34;
};

struct Player_14fad0 {
    char pad0[0x11c];
    PlayerCfg *cfg;
    char pad120[0x140 - 0x120];
    int mode;
    char pad144[0x1ae0 - 0x144];
    V3_14fad0 v1ae0;
    char pad1aec[0x1af8 - 0x1aec];
    V3_14fad0 v1af8;
    void FUN_000359c0(int a);
    void FUN_00035550(V3_14fad0 *out);
    void FUN_000357a0(const V3_14fad0 *v);
};

struct Mgr_14fad0 {
    Player_14fad0 *FUN_00059a30();
    bool FUN_00059a50(V3_14fad0 *out);
};

struct Holder_14fad0 {
    Mgr_14fad0 *FUN_000592a0();
};

struct Grav {
    char pad0[0x10];
    V3_14fad0 v;
};

float __cdecl FUN_00224f10(const V3_14fad0 *v);
void __cdecl FUN_00224d70(float angle, V3_14fad0 *v);

class Owner_14fad0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Target_14fad0 *vfunc_3();
};

union Arg1_14fad0 {
    int skip;
    float angle;
};

class HitFloatAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(Arg1_14fad0 a, float dt);
    char pad04[0x20 - 4];
    Owner_14fad0 *owner;
    FloatObject_14fad0 *floatObj;
    float time;
    float speed;
    float f30;
    float f34;
};

bool HitFloatAction::vfunc_5(Arg1_14fad0 a, float dt)
{
    V3_14fad0 vecA;
    V3_14fad0 dir;
    V3_14fad0 vecB;
    V3_14fad0 pos;

    if (a.skip)
        return true;
    if (!floatObj)
        return false;
    Target_14fad0 *target = owner->vfunc_3();
    if (!target)
        return false;

    Holder_14fad0 *holder = (Holder_14fad0 *)owner;
    Mgr_14fad0 *mgr = holder->FUN_000592a0();
    Player_14fad0 *pl = mgr->FUN_00059a30();
    pl->FUN_000359c0(3);
    a.angle = FUN_00224f10(&target->size);
    dir = (*(V3_14fad0*)&DAT_004afa08);
    FUN_00224d70(a.angle, &dir);
    hulk_freg k = dt * speed;          // x87: k stays in st(0) for both products
    dir.x = dir.x * k;
    dir.z = dir.z * k;
    mgr->FUN_00059a50(&pos);

    if (pl->mode == 4) {
        vecA = pl->v1af8;
        vecB.x = 0.0f;
        vecB.y = 0.0f;
        vecB.z = 0.0f;
        if (vecA.FUN_0022d2b0(&vecB, 0.00001f)) {
            vecA = pl->v1ae0;
            vecB.x = 0.0f;
            vecB.y = 0.0f;
            vecB.z = 0.0f;
            if (vecA.FUN_0022d2b0(&vecB, 0.00001f)) {
                pl->FUN_00035550(&vecA);
                vecA.x = vecA.x * (*(float*)&DAT_003f3388);
                vecA.z = vecA.z * (*(float*)&DAT_003f3388);
            }
        }
        vecA.y = 0.0f;
        vecA.FUN_0022d110();
        float s = pl->cfg->f34;
        vecA.x = vecA.x * s;
        vecA.y = vecA.y * s;
        vecA.z = vecA.z * s;
        pl->FUN_000357a0(&vecA);
    } else if (pl->mode != 3) {
        dir.y = dir.y + pl->cfg->f2c;
    }

    dir.x = pos.x + dir.x;
    dir.y = pos.y + dir.y;
    dir.z = pos.z + dir.z;
    // x87: the new time is stored with fst and the register copy is compared with the limit
    hulk_freg t = time + dt;
    time = t;
    vecB = (*(Grav**)&DAT_00554c10)->v;
    a.angle = vecB.y * (*(float*)&DAT_003f3320);
    if (t > target->limit) {
        if (f34 < a.angle)
            f34 = a.angle;
    }
    // x87: the new f30 is stored with fst and the register copy feeds the position
    hulk_freg v = f30 - dt * f34;
    f30 = v;
    dir.y = v * dt + dir.y;
    floatObj->transform.FUN_0022be40(&dir);
    return true;
}
