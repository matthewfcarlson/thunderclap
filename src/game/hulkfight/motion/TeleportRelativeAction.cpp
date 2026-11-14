// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00175890..0x00175cc0 (kind game, layer game, confidence medium), dominant class hulkfight::motion::TeleportRelativeAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe744ac4 {
#define TREE_TU_END }
namespace fn_fe744ac4 {} using namespace fn_fe744ac4;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fe744ac4 {
class RefObj_175890 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_175890 {
  public:
    Action_175890();
    virtual void Update_00018b30();
    char pad[0x18];
};
class TeleportAction_175890 : public Action_175890 {
  public:
    int mTarget;
    RefObj_175890* mObj;
    TeleportAction_175890(int target, RefObj_175890* obj);
    virtual void Execute_00018b40();
};
extern void* hulk_at_00417f10[];
class Ref_1758e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1758e0 {
  public:
    void* vptr;
};
class TeleportAction_1758e0 : public Action_1758e0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1758e0* m20;
    ~TeleportAction_1758e0();
};
class Obj_175920 {
  public:
    virtual void V0();
    virtual void V1();
};
class Inner_175920 {
  public:
    void Init_0027af00();
};
class Action_175920 {
  public:
    Action_175920();
    virtual void A0();
};
class TeleportRelativeAction_175920 : public Action_175920 {
  public:
    TeleportRelativeAction_175920(int arg, Obj_175920* obj);
    virtual void A0();
    char pad04[0x18];
    int field1c;
    Obj_175920* field20;
    char pad24[4];
    Inner_175920 inner;
};
extern int hulk_at_00417f2c;
class Ref_175980 {
  public:
    virtual void f0();
    virtual void f1();
};
class Helper_175980 {
  public:
    void Clean_0027af50();
};
class Action_175980 {
  public:
    int* vptr;
    char pad[0x18];
};
class TeleportRelativeAction : public Action_175980 {
  public:
    int m1c;
    Ref_175980* m20;
    int pad24;
    Helper_175980 helper;
    void Destroy();
};
struct Vec3_1759c0 {
    float x, y, z;
};
struct Id_1759c0 {
    unsigned int lo, hi;
};
struct Matrix {
    char pad0[0x10];
    void FUN_0022c2b0(const Vec3_1759c0 *in, Vec3_1759c0 *out);
};
struct Flagged_1759c0 {
    char pad0[0x72];
    unsigned char flag72;
};
struct Holder_1759c0 {
    char pad0[0x74];
    Flagged_1759c0 *shield;
};
struct Node {
    char pad0[0x10];
    Matrix matrix;
    char pad_[0x40 - 0x10 - sizeof(Matrix)];
    Vec3_1759c0 pos;
    char pad4c[0x74 - 0x4c];
    Flagged_1759c0 *shield;
};
struct Game;
struct Actor_1759c0;
struct Tracer_1759c0 {
    bool FUN_0010aa90(Game *g, Vec3_1759c0 *a, Vec3_1759c0 *b, float scale, Vec3_1759c0 *o3, Vec3_1759c0 *o2, Vec3_1759c0 *o1,
                      Actor_1759c0 *actor, Node *n, int zero0, int zero1);
};
struct Actor_1759c0 {
    char pad0[0x12c];
    Holder_1759c0 *holder;
    char pad130[0x328 - 0x130];
    Node *node;
    char pad32c[0x1ca4 - 0x32c];
    Tracer_1759c0 *tracer;
    bool FUN_0003f400(Vec3_1759c0 *p);
    void FUN_00036e70(Id_1759c0 *id, int v);
};
struct Body_1759c0 {
    Actor_1759c0 *FUN_00059a30();
};
struct Owner_1759c0 {
    Body_1759c0 *FUN_000592a0();
};
struct HitList;
struct Manager_1759c0 {
    bool FUN_002ee140(HitList *list, Vec3_1759c0 *from, Vec3_1759c0 *to, int flags);
};
struct Params {
    char pad0[0x10];
    Vec3_1759c0 v10;
    Vec3_1759c0 limit;
    float scale;
};
} // namespace fn_fe744ac4
extern "C" { extern Game *DAT_004dd700; }
namespace fn_fe744ac4 {
extern "C" HitList *FUN_00202f00();
} // namespace fn_fe744ac4
namespace hulkfight { namespace motion {
class TeleportRelativeAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int mode, float dt);

    char pad04[0x18];
    Params *params;  // 0x1c
    Owner_1759c0 *owner;    // 0x20
    char pad24[4];
    Id_1759c0 id;           // 0x28
};
} }

namespace fn_fe744ac4 {

// 0x00175890 FUN_00175890 (72 B): matches/0x00175890.cpp
// sym: ??0TeleportAction_175890@fn_fe744ac4@@QAE@HPAVRefObj_175890@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
TeleportAction_175890::TeleportAction_175890(int target, RefObj_175890* obj) {
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


// 0x001758e0 FUN_001758e0 (50 B): matches/0x001758e0.cpp
// sym: ??1TeleportAction_1758e0@fn_fe744ac4@@QAE@XZ
TeleportAction_1758e0::~TeleportAction_1758e0() {
    vptr = hulk_at_00417f10;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_1758e0 *)this)->FUN_002326a0();
}


// 0x00175920 FUN_00175920 (96 B): matches/0x00175920.cpp
// sym: ??0TeleportRelativeAction_175920@fn_fe744ac4@@QAE@HPAVObj_175920@1@@Z
TeleportRelativeAction_175920::TeleportRelativeAction_175920(int arg, Obj_175920* obj) {
    field1c = 0;
    field20 = 0;
    inner.Init_0027af00();
    field1c = arg;
    if (obj)
        obj->V0();
    if (field20)
        field20->V1();
    field20 = obj;
    ((owners::Target_27b040 *)&inner)->FUN_0027b040((hulk_uintptr)((const char*)((hulk_intptr)((char*)&DAT_00417da4))));
}


// 0x00175980 FUN_00175980 (58 B): matches/0x00175980.cpp
// sym: ?Destroy@TeleportRelativeAction@fn_fe744ac4@@QAEXXZ
void TeleportRelativeAction::Destroy() {
    vptr = &hulk_at_00417f2c;
    _ReadWriteBarrier();
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    helper.Clean_0027af50();
    ((fight::Action *)(Action_175980 *)this)->FUN_002326a0();
}

} // namespace fn_fe744ac4

// 0x001759c0 hulkfight::motion::TeleportRelativeAction::vfunc_5 (763 B): equivalent/0x001759c0.cpp
// sym: ?vfunc_5@TeleportRelativeAction@motion@hulkfight@@UAE_NHM@Z @03145b120ccc @w77b7dc4eff73
// STATUS: equivalent (tools/equiv.py level 3: 127 inputs, branch coverage 35/38, incomplete)
// hulkfight::motion::TeleportRelativeAction::vfunc_5 @ 0x001759c0
bool hulkfight::motion::TeleportRelativeAction::vfunc_5(int mode, float dt)
{
    if (mode != 0)
        return true;
    if (owner == 0)
        return false;
    Actor_1759c0 *actor = owner->FUN_000592a0()->FUN_00059a30();
    Node *node = actor->node;
    if (node == 0)
        return false;

    Vec3_1759c0 in = params->v10;
    Vec3_1759c0 t;
    node->matrix.FUN_0022c2b0(&in, &t);

    Vec3_1759c0 q = params->limit;
    if (q.x != 0.0f) {
        Vec3_1759c0 r = params->limit;
        t.x = (t.x < r.x) ? r.x : t.x;
    }
    q = params->limit;
    if (q.y != 0.0f) {
        Vec3_1759c0 r = params->limit;
        t.y = (t.y < r.y) ? r.y : t.y;
    }
    q = params->limit;
    if (q.z != 0.0f) {
        Vec3_1759c0 r = params->limit;
        t.z = (t.z < r.z) ? r.z : t.z;
    }

    if (node->shield)
        node->shield->flag72 = 0;
    if (actor->holder && actor->holder->shield)
        actor->holder->shield->flag72 = 0;

    Tracer_1759c0 *tracer = actor->tracer;
    Game *game = DAT_004dd700;
    if (tracer && game) {
        DAT_004d2a3c = 2;
        (*(char*)&DAT_00554c1c) = 1;
        (*(float*)&DAT_00554c18) = 0.5f;
        Vec3_1759c0 s = node->pos;
        Vec3_1759c0 d;
        d.x = t.x - s.x;
        d.y = t.y - s.y;
        d.z = t.z - s.z;
        Vec3_1759c0 o2;
        Vec3_1759c0 o3;
        o2.z = d.z;
        float scale = params->scale;
        if (actor->tracer->FUN_0010aa90(game, &s, &t, scale, &o3, &o2, &d, actor, node, 0, 1))
            actor->FUN_0003f400(&t);
        else
            actor->FUN_00036e70(&id, 1);
    } else {
        HitList *list = FUN_00202f00();
        (*(float*)&DAT_00554c18) = (*(float*)&DAT_004b8540);
        DAT_004d2a3c = 2;
        (*(char*)&DAT_00554c1c) = 0;
        if ((*(Manager_1759c0**)&DAT_00554c14)->FUN_002ee140(list, &node->pos, &t, 0))
            actor->FUN_00036e70(&id, 1);
        else
            actor->FUN_0003f400(&t);
    }

    if (node->shield)
        node->shield->flag72 = 1;
    if (actor->holder && actor->holder->shield)
        actor->holder->shield->flag72 = 1;
    return true;
}

