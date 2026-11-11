// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014f980..0x0014fda0 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitFloatAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f10ad346 {
#define TREE_TU_END }
namespace fn_f10ad346 {} using namespace fn_f10ad346;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f10ad346 {
struct Vec3_14f980 {
    float x, y, z;
};
struct Transform_14f980 {
    void FUN_00221d20(float v);
};
struct ResourceName_14f980 {
    char data[12];
};
class JointDriver_14f980 {
public:
    virtual void vfunc_0();
    char pad04[4];
    ResourceName_14f980 name;
    int mode;
    Transform_14f980 transform;
    JointDriver_14f980 *FUN_002248f0(int id);
};
struct Target_14f980 {
    char pad0[0x28];
    Vec3_14f980 size;
    char pad34[0x64 - 0x34];
    int field64;
};
struct Scene_14f980 {
    char pad0[0x40];
    Vec3_14f980 origin;
    void FUN_00222890(JointDriver_14f980 *obj, float a, float b, float c, float d, float e, float f);
};
struct HitData_14f980 {
    char pad0[0x14];
    unsigned char useSize;
    char pad15[3];
    float sizeBias;
    float p;
    float q;
    float r;
};
void *__fastcall FUN_000592a0(void *owner);
extern "C" void *__fastcall FUN_00059a30(void *x);
extern "C" Scene_14f980 *__fastcall FUN_00059a40(void *x);
hulk_freg __cdecl FUN_00224f10(Vec3_14f980 *v);
class Owner_14f980 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Target_14f980 *vfunc_3();
};
class HitFloatAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x18];
    HitData_14f980 *data;
    Owner_14f980 *owner;
    JointDriver_14f980 *floatObj;
    char pad28[4];
    float outLen;
    float outA;
    float outB;
};
struct Two_14fd70 {
    void* f();
};


// 0x0014f980 hulkfight::motion::HitFloatAction::vfunc_3 (335 B): equivalent/0x0014f980.cpp
// sym: ?vfunc_3@HitFloatAction@fn_f10ad346@@UAE_NHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 19972 inputs, branch coverage 10/10)
// hulkfight::motion::HitFloatAction::vfunc_3 @ 0x0014f980
bool HitFloatAction::vfunc_3(int a, int b)
{
    if (!owner)
        return false;
    void *h = FUN_000592a0(owner);
    FUN_00059a30(h);
    Scene_14f980 *scene = FUN_00059a40(h);
    if (!scene)
        return false;
    Target_14f980 *target = owner->vfunc_3();
    if (!target)
        return false;

    Vec3_14f980 pos = scene->origin;
    hulk_freg p = data->p;
    hulk_freg q = data->q;
    hulk_freg r = data->r;

    void *mem = FUN_00263ea0(0x70);
    JointDriver_14f980 *obj = 0;
    if (mem)
        obj = ((JointDriver_14f980 *)mem)->FUN_002248f0(0);
    floatObj = obj;
    ((owners::Target_27b040 *)&(obj->name))->FUN_0027b040((hulk_uintptr)"hitFloat");

    int mode = 1;
    if (data->useSize) {
        mode = 3;
        float arg1 = FUN_00224f10(&target->size) + data->sizeBias;
        floatObj->transform.FUN_00221d20(arg1);
    }
    floatObj->mode = mode;
    floatObj->vfunc_0();
    ((owners::Target_22be40 *)&(floatObj->transform))->FUN_0022be40((const int *)(const Vec3_14f980 *)(&pos));
    scene->FUN_00222890(floatObj, -1.0f, p, 1.0f, q, r, -1.0f);
    outLen = (float)sqrt(target->size.x * target->size.x + target->size.z * target->size.z);
    outA = target->size.y;
    outB = *(float *)&target->field64;
    return true;
}

} // namespace fn_f10ad346

// 0x0014fad0 hulkfight::motion::HitFloatAction::vfunc_5 (668 B): equivalent/0x0014fad0.cpp [wrapped: conflict: HitFloatAction]
// sym: ?vfunc_5@HitFloatAction@fn_0014fad0@@UAE_NTArg1_14fad0@2@M@Z
namespace fn_0014fad0 {
// STATUS: equivalent (tools/equiv.py level 3: 3037 inputs, branch coverage 18/18; Wine build 3036 inputs, 18/18)
// hulkfight::motion::HitFloatAction::vfunc_5 @ 0x0014fad0

struct V3_14fad0 {
    float x, y, z;
    bool FUN_0022d2b0(const V3_14fad0 *other, float eps);
    hulk_freg FUN_0022d110();
};

struct Transform_14fad0 {
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
    void FUN_00035550(V3_14fad0 *out);
};

struct Mgr_14fad0 {
    Player_14fad0 *FUN_00059a30();
    bool FUN_00059a50(V3_14fad0 *out);
};

struct Holder_14fad0 {
};

struct Grav {
    char pad0[0x10];
    V3_14fad0 v;
};

hulk_freg __cdecl FUN_00224f10(const V3_14fad0 *v);
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
    Mgr_14fad0 *mgr = ((Mgr_14fad0 *)((owners::Object_592a0 *)holder)->FUN_000592a0());
    Player_14fad0 *pl = mgr->FUN_00059a30();
    ((owners::C_359c0 *)pl)->FUN_000359c0(3);
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
        ((owners::C_357a0 *)pl)->FUN_000357a0((float *)(const V3_14fad0 *)(&vecA));
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
    ((owners::Target_22be40 *)&(floatObj->transform))->FUN_0022be40((const int *)(const V3_14fad0 *)(&dir));
    return true;
}
} // namespace fn_0014fad0


// 0x0014fd70 hulkfight::motion::HitFloatAction::vfunc_4 (37 B): matches/0x0014fd70.cpp
// sym: ?vfunc_4@HitFloatAction@motion@hulkfight@@UAEXXZ
// Same code shape as 0x00134160 (propagated; names are from that function)
void hulkfight::motion::HitFloatAction::vfunc_4() {
    void* x = (*(One * *)&this->f_20)->f();
    void* y = ((Two_14fd70*)x)->f();
    if (y)
        ((Three*)y)->f((*(void * *)&this->f_24), 0);
}

