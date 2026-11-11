// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00049c80..0x0004a210 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f342e0ab {
#define TREE_TU_END }
namespace fn_f342e0ab {} using namespace fn_f342e0ab;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f342e0ab {
class Obj_49cc0 {
  public:
    Obj_49cc0* b();
    int c();
};
class Helper_49d40 {
  public:
    void* Second();
};
extern int* gTable_49d90;
class CCondition_49d90 {
  public:
    virtual int vfunc_0(int);
};
struct Shape_49de0 {
    char pad0[0x14];
    int size;
};
struct Body_49de0 {
    char pad0[0x11c];
    Shape_49de0 *shape;
};
struct Fighter_49de0 {
    char pad0[0x330];
    Body_49de0 *b330;
    Body_49de0 *b334;
    Body_49de0 *b338;
};
struct Anchor_49de0 {
    Fighter_49de0 *FUN_00059a30();
};
struct FightHandle_49de0 {
};
extern int* gTable_49e80;
class CCondition_49e80 {
  public:
    virtual int vfunc_0(int);
};
extern "C" void __cdecl FUN_000964a0(char*, int, const char*, ...);
class Obj_49ed0 {
    char pad[0x10];

  public:
    char Format(const char* s);
};
extern int* gTable_49f10;
class CCondition_49f10 {
  public:
    virtual int vfunc_0(int);
};
extern int* gTable_49ff0;
class CCondition_49ff0 {
  public:
    virtual int vfunc_0(int);
};
extern int* gTable_4a0d0;
class CCondition_4a0d0 {
  public:
    virtual int vfunc_0(int);
};

} // namespace fn_f342e0ab

// 0x00049c80 CIsInvincibleCondition::vfunc_0 (5 B): matches/0x00049c80.cpp [wrapped: conflict: CCondition; CIsInvincibleCondition; fight::Condition; fight::Param]
// sym: ?vfunc_0@CIsInvincibleCondition@fn_00049c80@@UAEHH@Z
namespace fn_00049c80 {
class CCondition {
  public:
    virtual int vfunc_0();
};
namespace fight {
class Condition {
  public:
    virtual int vfunc_3();
};
class Param {
  public:
    virtual int vfunc_1();
    virtual int vfunc_2();
    virtual int vfunc_4();
};
} // namespace fight
class CIsInvincibleCondition : public CCondition, public fight::Condition, public fight::Param {
  public:
    virtual int vfunc_0(int);
};
int CIsInvincibleCondition::vfunc_0(int) {
    return 0;
}
} // namespace fn_00049c80

namespace fn_f342e0ab {

// 0x00049cc0 CIsInvincibleCondition::vfunc_7 (26 B): matches/0x00049cc0.cpp
// sym: ?vfunc_7@fn_f342e0ab@@YGHPAVObj_49cc0@1@@Z
int __stdcall vfunc_7(Obj_49cc0* p) {
    p = ((Obj_49cc0 *)((owners::Object_592a0 *)p)->FUN_000592a0());
    p = p->b();
    return p->c();
}

} // namespace fn_f342e0ab

// 0x00049d00 CIsGrappledCondition::vfunc_0 (5 B): matches/0x00049d00.cpp [wrapped: conflict: CCondition; CIsGrappledCondition; fight::Condition; fight::Param]
// sym: ?vfunc_0@CIsGrappledCondition@fn_00049d00@@UAEHH@Z
namespace fn_00049d00 {
// Same code shape as 0x00049c80 (propagated; names are from that function)
class CCondition {
  public:
    virtual int vfunc_0();
};
namespace fight {
class Condition {
  public:
    virtual int vfunc_3();
};
class Param {
  public:
    virtual int vfunc_1();
    virtual int vfunc_2();
    virtual int vfunc_4();
};
} // namespace fight
class CIsGrappledCondition : public CCondition, public fight::Condition, public fight::Param {
  public:
    virtual int vfunc_0(int);
};
int CIsGrappledCondition::vfunc_0(int) {
    return 0;
}
} // namespace fn_00049d00


// 0x00049d40 CIsGrappledCondition::vfunc_7 (34 B): matches/0x00049d40.cpp
// sym: ?vfunc_7@CIsGrappledCondition@@UAE_NPAX@Z
bool CIsGrappledCondition::vfunc_7(void* __p0) { Helper_49d40 * p = (Helper_49d40 *)__p0;

    void* a = ((void *)((owners::Object_592a0 *)p)->FUN_000592a0());
    void* b = ((Helper_49d40*)a)->Second();
    return *(int*)((char*)b + 0x338) != 0;
}

namespace fn_f342e0ab {

// 0x00049d70 FUN_00049d70 (19 B): matches/0x00049d70.cpp
// sym: ?FUN_00049d70@fn_f342e0ab@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00049d70() {
    FUN_00234810(((char*)&DAT_004dc4f8), ((char*)&DAT_004dc4fc));
}

} // namespace fn_f342e0ab

// 0x00049d90 CGrappleSizeCondition::vfunc_0 (16 B): matches/0x00049d90.cpp
// sym: ?vfunc_0@CGrappleSizeCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CGrappleSizeCondition::vfunc_0(int index) {
    int* p = gTable_49d90;
    return p[index];
}


// 0x00049de0 CGrappleSizeCondition::vfunc_7 (117 B): equivalent/0x00049de0.cpp
// sym: ?vfunc_7@CGrappleSizeCondition@@UAE_NPAX@Z
// STATUS: equivalent (tools/equiv.py level 3: 3024 inputs, branch coverage 19/20, incomplete)
// CGrappleSizeCondition::vfunc_7 @ 0x00049de0
bool CGrappleSizeCondition::vfunc_7(void* __p0) { FightHandle_49de0 * h = (FightHandle_49de0 *)__p0;

    if (h == 0)
        return false;
    Fighter_49de0 *f = ((Anchor_49de0 *)((owners::Object_592a0 *)h)->FUN_000592a0())->FUN_00059a30();
    Body_49de0 *body = f->b334;
    if (body == 0)
        body = f->b330;
    if (body == 0)
        body = f->b338;
    if (body == 0)
        return false;
    Shape_49de0 *shape = body->shape;
    if (shape == 0)
        return false;
    if (this->f_0c == 0)
        return shape->size == this->f_10;
    if (this->f_0c == 1)
        return shape->size != this->f_10;
    return false;
}

namespace fn_f342e0ab {

// 0x00049e60 FUN_00049e60 (19 B): matches/0x00049e60.cpp
// sym: ?FUN_00049e60@fn_f342e0ab@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00049e60() {
    FUN_00234810(((char*)&DAT_004dc500), ((char*)&DAT_004dc504));
}

} // namespace fn_f342e0ab

// 0x00049e80 CLuaNumberCondition::vfunc_0 (16 B): matches/0x00049e80.cpp
// sym: ?vfunc_0@CLuaNumberCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CLuaNumberCondition::vfunc_0(int index) {
    int* p = gTable_49e80;
    return p[index];
}

namespace fn_f342e0ab {

// 0x00049ed0 FUN_00049ed0 (29 B): matches/0x00049ed0.cpp
// sym: ?Format@Obj_49ed0@fn_f342e0ab@@QAEDPBD@Z
char Obj_49ed0::Format(const char* s) {
    FUN_000964a0((char*)((char*)this + 0x10), 0x40, "%s", s);
    return 1;
}


// 0x00049ef0 FUN_00049ef0 (19 B): matches/0x00049ef0.cpp
// sym: ?FUN_00049ef0@fn_f342e0ab@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00049ef0() {
    FUN_00234810(((char*)&DAT_004dc508), ((char*)&DAT_004dc50c));
}

} // namespace fn_f342e0ab

// 0x00049f10 CCharacterTemplateCondition::vfunc_0 (16 B): matches/0x00049f10.cpp
// sym: ?vfunc_0@CCharacterTemplateCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CCharacterTemplateCondition::vfunc_0(int index) {
    int* p = gTable_49f10;
    return p[index];
}


// 0x00049f50 FUN_00049f50 (31 B): matches/0x00049f50.cpp [wrapped: conflict: CCondition]
// sym: ?Run@CCharacterTemplateCondition_49f50@fn_00049f50@@QAEXXZ
namespace fn_00049f50 {
// Same code shape as 0x0004a030 (propagated; names are from that function)
extern int vtableA;
extern int vtableB;
class Part_49f50 {
  public:
    void Init();
};
class CCondition {
  public:
    virtual void F();
};
class CCharacterTemplateCondition_49f50 : public CCondition {
  public:
    char pad[12];
    Part_49f50 part;
    void Run();
    void Finish();
};
void CCharacterTemplateCondition_49f50::Run() {
    *(hulk_intptr*)this = (hulk_intptr)&vtableA;
    part.Init();
    *(hulk_intptr*)this = (hulk_intptr)&vtableB;
    Finish();
}
} // namespace fn_00049f50


// 0x00049f70 CCharacterTemplateCondition::vfunc_7 (92 B): equivalent/0x00049f70.cpp [wrapped: conflict: CCharacterTemplateCondition]
// sym: ?vfunc_7@CCharacterTemplateCondition@fn_00049f70@@QAE_NPAUConditionContext@2@@Z
namespace fn_00049f70 {
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 14/14)
// CCharacterTemplateCondition::vfunc_7 @ 0x00049f70
struct CharacterTemplate { unsigned __int64 FUN_000443c0(); };
struct CharacterData { char pad[0x11c]; CharacterTemplate* characterTemplate; };
struct CharacterState { CharacterData* FUN_00059a30(); };
struct ConditionContext { CharacterState* FUN_000592a0(); };
struct CCharacterTemplateCondition {
    void* vtable;
    char pad[8];
    int comparison;
    unsigned int templateLow;
    unsigned int templateHigh;
    bool vfunc_7(ConditionContext* context);
};
bool CCharacterTemplateCondition::vfunc_7(ConditionContext* context) {
    CharacterData* data = context->FUN_000592a0()->FUN_00059a30();
    unsigned __int64 templateId = data->characterTemplate ? data->characterTemplate->FUN_000443c0() : 0;
    bool same = (unsigned int)templateId == templateLow && (unsigned int)(templateId >> 32) == templateHigh;
    if (comparison == 0) return same;
    if (comparison == 1) return !same;
    return false;
}
} // namespace fn_00049f70

namespace fn_f342e0ab {

// 0x00049fd0 FUN_00049fd0 (19 B): matches/0x00049fd0.cpp
// sym: ?FUN_00049fd0@fn_f342e0ab@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00049fd0() {
    FUN_00234810(((char*)&DAT_004dc510), ((char*)&DAT_004dc514));
}

} // namespace fn_f342e0ab

// 0x00049ff0 CCharacterTemplateVariationCondition::vfunc_0 (16 B): matches/0x00049ff0.cpp
// sym: ?vfunc_0@CCharacterTemplateVariationCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CCharacterTemplateVariationCondition::vfunc_0(int index) {
    int* p = gTable_49ff0;
    return p[index];
}


// 0x0004a000 FUN_0004a000 (35 B): matches/0x0004a000.cpp [wrapped: conflict: CCharacterTemplateVariationCondition]
// sym: ??0CCharacterTemplateVariationCondition@fn_0004a000@@QAE@XZ
namespace fn_0004a000 {
class CCondition_4a000 {
  public:
    CCondition_4a000(int);
    virtual void v();
    char pad[8];
};
class Member {
  public:
    Member();
};
class CCharacterTemplateVariationCondition : public CCondition_4a000 {
  public:
    CCharacterTemplateVariationCondition();
    virtual void v();
    int x;
    Member m;
};
CCharacterTemplateVariationCondition::CCharacterTemplateVariationCondition() : CCondition_4a000(0), x(0), m() {}
} // namespace fn_0004a000


// 0x0004a030 FUN_0004a030 (31 B): matches/0x0004a030.cpp [wrapped: conflict: CCharacterTemplateVariationCondition; CCondition]
// sym: ?Run@CCharacterTemplateVariationCondition@fn_0004a030@@QAEXXZ
namespace fn_0004a030 {
extern int vtableA;
extern int vtableB;
class Part_4a030 {
  public:
    void Init();
};
class CCondition {
  public:
    virtual void F();
};
class CCharacterTemplateVariationCondition : public CCondition {
  public:
    char pad[12];
    Part_4a030 part;
    void Run();
    void Finish();
};
void CCharacterTemplateVariationCondition::Run() {
    *(hulk_intptr*)this = (hulk_intptr)&vtableA;
    part.Init();
    *(hulk_intptr*)this = (hulk_intptr)&vtableB;
    Finish();
}
} // namespace fn_0004a030


// 0x0004a050 CCharacterTemplateVariationCondition::vfunc_7 (92 B): matches/0x0004a050.cpp [wrapped: conflict: CCharacterTemplateVariationCondition]
// sym: ?vfunc_7@CCharacterTemplateVariationCondition@fn_0004a050@@UAE_NPAVArg_4a050@2@@Z
namespace fn_0004a050 {
class Thing_4a050 {
  public:
    char pad[0x11c];
    void* p;
};
class Agent_4a050 {
  public:
    Thing_4a050* get();
};
class Arg_4a050 {
  public:
    Agent_4a050* get();
};
class Item_4a050 {
  public:
    __int64 get();
};
class CCharacterTemplateVariationCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual bool vfunc_7(Arg_4a050*);
    char pad[4];
    int mode;
    __int64 key;
};
bool CCharacterTemplateVariationCondition::vfunc_7(Arg_4a050* arg) {
    Thing_4a050* t = arg->get()->get();
    __int64 v;
    if (!t->p)
        v = 0;
    else
        v = ((Item_4a050*)t->p)->get();
    switch (mode) {
    case 0:
        return v == key;
    case 1:
        return v != key;
    default:
        return false;
    }
}
} // namespace fn_0004a050

namespace fn_f342e0ab {

// 0x0004a0b0 FUN_0004a0b0 (19 B): matches/0x0004a0b0.cpp
// sym: ?FUN_0004a0b0@fn_f342e0ab@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0004a0b0() {
    FUN_00234810(((char*)&DAT_004dc518), ((char*)&DAT_004dc51c));
}

} // namespace fn_f342e0ab

// 0x0004a0d0 CGrappleCharacterTemplateCondition::vfunc_0 (16 B): matches/0x0004a0d0.cpp
// sym: ?vfunc_0@CGrappleCharacterTemplateCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CGrappleCharacterTemplateCondition::vfunc_0(int index) {
    int* p = gTable_4a0d0;
    return p[index];
}


// 0x0004a110 FUN_0004a110 (31 B): matches/0x0004a110.cpp [wrapped: conflict: CCondition]
// sym: ?Run@CGrappleCharacterTemplateCondition_4a110@fn_0004a110@@QAEXXZ
namespace fn_0004a110 {
// Same code shape as 0x0004a030 (propagated; names are from that function)
extern int vtableA;
extern int vtableB;
class Part_4a110 {
  public:
    void Init();
};
class CCondition {
  public:
    virtual void F();
};
class CGrappleCharacterTemplateCondition_4a110 : public CCondition {
  public:
    char pad[12];
    Part_4a110 part;
    void Run();
    void Finish();
};
void CGrappleCharacterTemplateCondition_4a110::Run() {
    *(hulk_intptr*)this = (hulk_intptr)&vtableA;
    part.Init();
    *(hulk_intptr*)this = (hulk_intptr)&vtableB;
    Finish();
}
} // namespace fn_0004a110


// 0x0004a160 CGrappleCharacterTemplateCondition::vfunc_7 (132 B): equivalent/0x0004a160.cpp [wrapped: conflict: CGrappleCharacterTemplateCondition]
// sym: ?vfunc_7@CGrappleCharacterTemplateCondition@fn_0004a160@@QAE_NPAX@Z
namespace fn_0004a160 {
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 23/24, incomplete)
// CGrappleCharacterTemplateCondition::vfunc_7 @ 0x0004a160
struct Fighter_4a160 {
    char pad[4];
};
Fighter_4a160 *__fastcall FUN_000592a0(void *owner);

struct Unit_4a160 {
    char pad00[0x11c];
    struct Ids_4a160 *ids;
};

struct Ids_4a160 {
    unsigned __int64 FUN_000443c0();
};

struct Stats_4a160 {
    char pad00[0x330];
    Unit_4a160 *a330;
    Unit_4a160 *a334;
    Unit_4a160 *a338;
};
extern "C" Stats_4a160 *__fastcall FUN_00059a30(Fighter_4a160 *f);

class CGrappleCharacterTemplateCondition {
public:
    virtual void vfunc_0();
    char pad04[8];
    int mode;
    unsigned int idLo;
    unsigned int idHi;
    bool vfunc_7(void *owner);
};

bool CGrappleCharacterTemplateCondition::vfunc_7(void *owner)
{
    if (owner == 0)
        return false;
    Stats_4a160 *stats = FUN_00059a30(FUN_000592a0(owner));
    Unit_4a160 *unit = stats->a334;
    if (unit == 0) {
        unit = stats->a330;
        if (unit == 0) {
            unit = stats->a338;
            if (unit == 0)
                return false;
        }
    }
    unsigned int lo = 0;
    unsigned int hi = 0;
    if (unit->ids != 0) {
        unsigned __int64 id = unit->ids->FUN_000443c0();
        lo = (unsigned int)id;
        hi = (unsigned int)(id >> 32);
    }
    if (mode == 0)
        return lo == idLo && hi == idHi;
    if (mode == 1)
        return !(lo == idLo && hi == idHi);
    return false;
}
} // namespace fn_0004a160

namespace fn_f342e0ab {

// 0x0004a1f0 FUN_0004a1f0 (19 B): matches/0x0004a1f0.cpp
// sym: ?FUN_0004a1f0@fn_f342e0ab@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0004a1f0() {
    FUN_00234810(((char*)&DAT_004dc520), ((char*)&DAT_004dc524));
}

} // namespace fn_f342e0ab
