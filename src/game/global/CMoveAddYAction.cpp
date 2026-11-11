// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00014f50..0x00014fe0 (kind game, layer game, confidence medium), dominant class CMoveAddYAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_fe56d8f0 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fe56d8f0 {} using namespace fn_fe56d8f0;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fe56d8f0 {
struct Vec3_14f50 { float x, y, z; };
struct Target_14f50 {
    void FUN_00035720(Vec3_14f50 *v);
};
struct Globals_14f50 {
    Target_14f50 *FUN_00059a30();
};
struct Table_14f50 {
    Globals_14f50 *FUN_00059a30();
};
struct Owner_14f50 {
    Table_14f50 *FUN_000592a0();
};
class Driver {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual float v7();
    char pad04[0x10];
    float f14;
};
class CMoveAddYAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(float scale);
    virtual void vfunc_8();
    char pad04[0x18];
    Owner_14f50 *owner;
    Driver *driver;
};


// 0x00014f50 CMoveAddYAction::vfunc_7 (135 B): matches/0x00014f50.cpp
// sym: ?vfunc_7@CMoveAddYAction@fn_fe56d8f0@@UAE_NM@Z
// CMoveAddYAction::vfunc_7 @ 0x00014f50
bool CMoveAddYAction::vfunc_7(float scale)
{
    Target_14f50 *target = (Target_14f50 *)owner->FUN_000592a0()->FUN_00059a30();
    hulk_freg rate = driver->v7();
    if (rate <= 0.0f)
        return false;
    Vec3_14f50 v;
    v.x = 0.0f;
    v.y = 1.0f;
    v.z = 0.0f;
    hulk_freg t = driver->f14 / rate * scale;
    v.x = 0.0f * t;
    v.y = t;
    v.z = 0.0f * t;
    target->FUN_00035720(&v);
    return true;
}

} // namespace fn_fe56d8f0
