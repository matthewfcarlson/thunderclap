// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00175fd0..0x00176270 (kind game, layer game, confidence medium), dominant class hulkfight::motion::SuckInPropsAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f3a32d27 {
#define TREE_TU_END }
namespace fn_f3a32d27 {} using namespace fn_f3a32d27;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f3a32d27 {
class RefObj_175fd0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_175fd0 {
  public:
    Action_175fd0();
    virtual void Update();
    char pad[0x18];
};
class SuckInPropsAction_175fd0 : public Action_175fd0 {
  public:
    int mTarget;
    RefObj_175fd0* mObj;
    SuckInPropsAction_175fd0(int target, RefObj_175fd0* obj);
    virtual void Execute();
};
extern void* hulk_at_00417f80[];
class Ref_176020 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_176020 {
  public:
    void* vptr;
};
class SuckInPropsAction_176020 : public Action_176020 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_176020* m20;
    ~SuckInPropsAction_176020();
};
struct Vec3_176060 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    void FUN_000344b0(float s);
    hulk_freg FUN_00018990();
};
class Scaler_176060 {
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
    virtual float GetScale();
};
struct ScalerOwner {
    char pad00[0x70];
    Scaler_176060* scaler;
};
struct Controller_176060 {
    char pad00[0x10];
    ScalerOwner* owner;
};
struct Prop_176060 {
    char pad00[0xa0];
    Controller_176060* controller;
    char pad04[0x114 - 0xa4];
    int field114;
    char pad118[0x1a1 - 0x118];
    char active;
    char pad1a2[0x1ed - 0x1a2];
    char hit;
    Vec3_176060* FUN_001d6b40();
    void FUN_001d86d0(Vec3_176060* dir, Vec3_176060* extra);
};
struct PropList_176060 {
    int FUN_001dcf50();
    Prop_176060* FUN_001dc0b0(int index);
};
} // namespace fn_f3a32d27
struct World {
    char pad00[0xc];
    PropList_176060* props;
};
namespace fn_f3a32d27 {
struct Anchor_176060 {
    bool FUN_00059a50(Vec3_176060* out);
};
struct Player_176060 {
    char pad00[0x10];
    Anchor_176060* anchor;
};
struct Clock_176060 {
    Player_176060* FUN_00059a30();
};
struct Target_176060 {
    Clock_176060* FUN_000592a0();
};
struct Config_176060 {
    char pad00[0x14];
    int maxHits;
    float strength;
    float range;
};
} // namespace fn_f3a32d27
namespace hulkfight { namespace motion {
class SuckInPropsAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool vfunc_5(int skip, float dt);

    char pad04[0x1c - 4];
    Config_176060* cfg;
    Target_176060* owner;
};
} }

namespace fn_f3a32d27 {

// 0x00175fd0 FUN_00175fd0 (72 B): matches/0x00175fd0.cpp
// sym: ??0SuckInPropsAction_175fd0@fn_f3a32d27@@QAE@HPAVRefObj_175fd0@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
SuckInPropsAction_175fd0::SuckInPropsAction_175fd0(int target, RefObj_175fd0* obj) {
    int* p = &mTarget;
    *p = 0;
    mObj = 0;
    mTarget = target;
    if (obj) {
        obj->AddRef();
    }
    if (mObj) {
        mObj->Release();
    }
    mObj = obj;
}


// 0x00176020 FUN_00176020 (50 B): matches/0x00176020.cpp
// sym: ??1SuckInPropsAction_176020@fn_f3a32d27@@QAE@XZ
SuckInPropsAction_176020::~SuckInPropsAction_176020() {
    vptr = hulk_at_00417f80;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_176020 *)this)->FUN_002326a0();
}

} // namespace fn_f3a32d27

// 0x00176060 hulkfight::motion::SuckInPropsAction::vfunc_5 (517 B): equivalent/0x00176060.cpp
// sym: ?vfunc_5@SuckInPropsAction@motion@hulkfight@@UAE_NHM@Z @ee0f31f273cc @wc248784d22e6
// STATUS: equivalent (tools/equiv.py level 3: 20041 inputs, branch coverage 31/32, incomplete)
// hulkfight::motion::SuckInPropsAction::vfunc_5 @ 0x00176060
namespace hulkfight { namespace motion {
bool SuckInPropsAction::vfunc_5(int skip, float dt)
{
    if (skip != 0)
        return true;
    if (dt == 0.0f)
        return true;

    int hits = 0;
    Clock_176060* clock = owner->FUN_000592a0();
    Player_176060* player = 0;
    if (clock)
        player = clock->FUN_00059a30();
    if (player == 0)
        return false;

    Vec3_176060 playerPos;
    player->anchor->FUN_00059a50(&playerPos);

    for (int i = 0; i < DAT_004dd700->props->FUN_001dcf50(); i++) {
        Prop_176060* prop = DAT_004dd700->props->FUN_001dc0b0(i);
        if (prop == 0)
            continue;
        if (prop->controller == 0)
            continue;
        if (prop->controller->owner == 0)
            continue;
        Scaler_176060* s = prop->controller->owner->scaler;
        if (s == 0)
            continue;
        if (s->GetScale() == 0.0f)
            continue;
        if (prop->active == 0)
            continue;
        if (prop->field114 != 0)
            continue;

        Vec3_176060 zero;
        zero.x = 0.0f;
        zero.y = 0.0f;
        zero.z = 0.0f;
        Vec3_176060* pp = prop->FUN_001d6b40();
        Vec3_176060 propPos = *pp;
        Vec3_176060 toPlayer;
        Vec3_176060 toProp;
        toProp.x = propPos.x - playerPos.x;
        toProp.y = propPos.y - playerPos.y;
        toProp.z = propPos.z - playerPos.z;
        toPlayer.x = playerPos.x - propPos.x;
        toPlayer.y = playerPos.y - propPos.y;
        toPlayer.z = playerPos.z - propPos.z;
        toPlayer.FUN_0022d110();
        hulk_freg num = cfg->strength;
        hulk_freg scale = num / prop->controller->owner->scaler->GetScale();
        toPlayer.FUN_000344b0(scale);
        Config_176060* c = cfg;
        if (!(toProp.FUN_00018990() < c->range))
            continue;
        hits++;
        if (hits > c->maxHits)
            break;
        if (hits > 8)
            break;
        prop->FUN_001d86d0(&toPlayer, &zero);
        prop->hit = 1;
    }
    return true;
}
} }

