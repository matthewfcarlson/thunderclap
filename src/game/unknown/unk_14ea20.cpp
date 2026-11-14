// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014ea20..0x0014ed50 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f0463da2 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f0463da2 {} using namespace fn_f0463da2;
#include "game/unknown.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f0463da2 {
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);
struct Contact_14ea20 {
    char pad00[0x50];
    int target;           // 0x50
};
struct Fighter_14ea20 {
    char pad00[0x328];
    int currentTarget;    // 0x328
};
struct Body_14ea20 {
    Fighter_14ea20* FUN_00059a30();
};
class Target_14ea20 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Contact_14ea20* v3();
    Body_14ea20* FUN_000592a0();
};
namespace hulkfight { namespace motion {
class CollisionTargetIsTargetCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(void* a1, Target_14ea20* target, void* a3);

    char pad04[8];
    unsigned char expected;   // 0x0c
};
} }
namespace fight {
class Params;
}
class CFightParams;
struct Stats_14ea90 {
    char pad0[0xc];
    int value;
};
struct Info_14ea90 {
    char pad0[0x50];
    Stats_14ea90* stats;
};
namespace fight {
class Params {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual Info_14ea90* GetInfo();
};
}
class CFightParams : public fight::Params {
public:
    virtual void c0();
};
namespace hulkfight { namespace motion {
class CollisionTargetTypeCondition {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual bool vfunc_6(int unused1, fight::Params* params, int unused2);
    char pad04[8];
    int compare;     // 0: equal, 1: not equal
    int kind;        // 0 -> type 1, 1 -> type 5
};
} }
extern void* __cdecl FUN_00344e74(void*, int, const char*, const char*, int);
struct Body_14eb10 {
    char pad0[0x11c];
    struct Sized* sized;    // 0x11c
};
struct Sized {
    char pad0[0x14];
    int size;               // 0x14
};
struct Link_14eb10 {
    char pad0[8];
    Body_14eb10* body;             // 0x08
    int kind;               // 0x0c
};
struct Holder_14eb10 {
    char pad0[0x4c];
    Link_14eb10* link;             // 0x4c
};
class Entity {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Holder_14eb10* vfunc_3();
};
namespace hulkfight { namespace motion {
class CollisionSourceSizeCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int unused1, Entity* entity, int unused2);
    char pad04[8];
    int mode;               // 0x0c
    int value;              // 0x10
};
} }
struct TypeDesc_14ed00 {
    void* vf;
};
extern TypeDesc_14ed00 hulk_at_00494b44;
extern TypeDesc_14ed00 hulk_at_00494b60;
class BattleObj {
  public:
    char pad[0x91];
    char mByte;
};
class FightObject {
  public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual BattleObj* GetBattleObj();
};
class Condition_14ed00 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    int mCond;
};
class fight_Param {
  public:
    virtual void pfunc_1();
    virtual void pfunc_2();
};
namespace hulkfight { namespace motion {
class CollisionDevastatorCondition : public Condition_14ed00, public fight_Param {
  public:
    virtual void dfunc_0();
    virtual void dfunc_1();
    virtual void dfunc_2();
    virtual bool vfunc_6(int a, FightObject* p, int c);
    char mByte;
};
} }


// 0x0014ea20 hulkfight::motion::CollisionTargetIsTargetCondition::vfunc_6 (106 B): equivalent/0x0014ea20.cpp
// sym: ?vfunc_6@CollisionTargetIsTargetCondition@motion@hulkfight@fn_f0463da2@@UAE_NPAXPAVTarget_14ea20@4@0@Z @fa366bb900d6 @w4846e0092024
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// hulkfight::motion::CollisionTargetIsTargetCondition::vfunc_6 @ 0x0014ea20
bool hulkfight::motion::CollisionTargetIsTargetCondition::vfunc_6(void* a1, Target_14ea20* target, void* a3)
{
    if (FUN_00344e74(target, 0, DAT_00494b44, DAT_00494b60, 0) == 0)
        return false;
    Fighter_14ea20* fighter = target->FUN_000592a0()->FUN_00059a30();
    Contact_14ea20* contact = target->v3();
    if (contact == 0)
        return false;
    return (contact->target == fighter->currentTarget) == expected;
}


// 0x0014ea90 hulkfight::motion::CollisionTargetTypeCondition::vfunc_6 (122 B): matches/0x0014ea90.cpp
// sym: ?vfunc_6@CollisionTargetTypeCondition@motion@hulkfight@fn_f0463da2@@UAE_NHPAVParams@fight@4@H@Z
// hulkfight::motion::CollisionTargetTypeCondition::vfunc_6 @ 0x0014ea90
namespace hulkfight { namespace motion {
bool CollisionTargetTypeCondition::vfunc_6(int unused1, fight::Params* params, int unused2) {
    if (!dynamic_cast<CFightParams*>(params))
        return false;
    Info_14ea90* info = params->GetInfo();
    if (!info)
        return false;
    Stats_14ea90* stats = info->stats;
    if (!stats)
        return false;
    int actual = stats->value;
    int expected = 0;
    switch (kind) {
    case 0:
        expected = 1;
        break;
    case 1:
        expected = 5;
        break;
    }
    switch (compare) {
    case 0:
        return expected == actual;
    case 1:
        return expected != actual;
    }
    return false;
}
} }


// 0x0014eb10 hulkfight::motion::CollisionSourceSizeCondition::vfunc_6 (127 B): equivalent/0x0014eb10.cpp
// sym: ?vfunc_6@CollisionSourceSizeCondition@motion@hulkfight@fn_f0463da2@@UAE_NHPAVEntity@4@H@Z @0b4943e87d78 @wae6d2ad38547
// STATUS: equivalent (tools/equiv.py level 3: 3019 inputs, branch coverage 20/20)
// hulkfight::motion::CollisionSourceSizeCondition::vfunc_6 @ 0x0014eb10
bool hulkfight::motion::CollisionSourceSizeCondition::vfunc_6(int unused1, Entity* entity, int unused2)
{
    if (!FUN_00344e74(entity, 0, DAT_00494b44, DAT_00494b60, 0))
        return false;
    Holder_14eb10* holder = entity->vfunc_3();
    if (!holder || !holder->link)
        return false;
    Link_14eb10* link = holder->link;
    if (link->kind != 1 || !link->body || !link->body->sized)
        return false;
    int size = link->body->sized->size;
    switch (mode) {
    case 0:
        return size == value;
    case 1:
        return size != value;
    }
    return false;
}

} // namespace fn_f0463da2

// 0x0014eb90 hulkfight::motion::CollisionTargetSizeCondition::vfunc_6 (127 B): equivalent/0x0014eb90.cpp [wrapped: conflict: Entity]
// sym: ?vfunc_6@CollisionTargetSizeCondition@motion@hulkfight@fn_0014eb90@@UAE_NHPAVEntity@4@H@Z @bb3ee98b6619 @w623ff78bfb0f
namespace fn_0014eb90 {
// STATUS: equivalent (tools/equiv.py level 3: 3023 inputs, branch coverage 20/20)
// hulkfight::motion::CollisionTargetSizeCondition::vfunc_6 @ 0x0014eb90
extern "C++" { extern char DAT_00494b44[]; }
extern "C++" { extern char DAT_00494b60[]; }
extern void* __cdecl FUN_00344e74(void*, int, const char*, const char*, int);

struct Body_14eb90 {
    char pad0[0x11c];
    struct Sized* sized;    // 0x11c
};

struct Sized {
    char pad0[0x14];
    int size;               // 0x14
};

struct Link_14eb90 {
    char pad0[8];
    Body_14eb90* body;             // 0x08
    int kind;               // 0x0c
};

struct Holder_14eb90 {
    char pad0[0x50];
    Link_14eb90* link;             // 0x50
};

class Entity {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Holder_14eb90* vfunc_3();
};

namespace hulkfight {
namespace motion {
class CollisionTargetSizeCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int unused1, Entity* entity, int unused2);
    char pad04[8];
    int mode;               // 0x0c
    int value;              // 0x10
};
}
}

bool hulkfight::motion::CollisionTargetSizeCondition::vfunc_6(int unused1, Entity* entity, int unused2)
{
    if (!FUN_00344e74(entity, 0, DAT_00494b44, DAT_00494b60, 0))
        return false;
    Holder_14eb90* holder = entity->vfunc_3();
    if (!holder || !holder->link)
        return false;
    Link_14eb90* link = holder->link;
    if (link->kind != 1 || !link->body || !link->body->sized)
        return false;
    int size = link->body->sized->size;
    switch (mode) {
    case 0:
        return size == value;
    case 1:
        return size != value;
    }
    return false;
}
} // namespace fn_0014eb90


// 0x0014ec60 hulkfight::motion::CollisionThrowCondition::vfunc_6 (71 B): equivalent/0x0014ec60.cpp [wrapped: conflict: DAT_00494b44; DAT_00494b60]
// sym: ?vfunc_6@CollisionThrowCondition@motion@hulkfight@fn_0014ec60@@QAEEPAXPAUFightTarget@4@0@Z @80cfb9ab0595 @w9c15859d3c29
namespace fn_0014ec60 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// hulkfight::motion::CollisionThrowCondition::vfunc_6 @ 0x0014ec60
extern char DAT_00494b44;
extern char DAT_00494b60;
extern "C++" void* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
struct FightTarget {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void* vfunc_3();
};
namespace hulkfight { namespace motion {
struct CollisionThrowCondition {
    char padding[12];
    unsigned char throwType;
    unsigned char vfunc_6(void*, FightTarget* target, void*);
};
unsigned char CollisionThrowCondition::vfunc_6(void*, FightTarget* target, void*) {
    if (!FUN_00344e74(target, 0, &DAT_00494b44, &DAT_00494b60, 0)) return 0;
    char* object = (char*)target->vfunc_3();
    if (!object) return 0;
    return throwType == (unsigned char)object[0x34];
}
}}
} // namespace fn_0014ec60

namespace fn_f0463da2 {

// 0x0014ed00 hulkfight::motion::CollisionDevastatorCondition::vfunc_6 (74 B): matches/0x0014ed00.cpp
// sym: ?vfunc_6@CollisionDevastatorCondition@motion@hulkfight@fn_f0463da2@@UAE_NHPAVFightObject@4@H@Z
bool hulkfight::motion::CollisionDevastatorCondition::vfunc_6(int a, FightObject* p, int c) {
    if (__RTDynamicCast(p, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0) == 0)
        return false;
    BattleObj* o = p->GetBattleObj();
    if (o == 0)
        return false;
    return mByte == o->mByte;
}

} // namespace fn_f0463da2
