// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004a560..0x0004a990 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f901265b {
#define TREE_TU_END }
namespace fn_f901265b {} using namespace fn_f901265b;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f901265b {
extern int* hulk_at_004dc540;
class CCondition_4a5c0 {
  public:
    virtual int vfunc_0(int);
};
struct A_4a600 {
    void* Fnf_000592a0();
};
struct B_4a600 {
    void* Fnf_00059a30();
};
struct Manager_4a600 {
    char pad[0x1b28];
    int field;
};
extern int* hulk_at_004dc548;
class CCondition_4a650 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc550;
class CCondition_4a6c0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc558;
class CCondition_4a730 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc560;
class CCondition_4a7a0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc568;
class CCondition_4a840 {
  public:
    virtual int vfunc_0(int);
};
extern int hulk_at_003f74e0, hulk_at_003f6d50;
class Sub_4a880 {
  public:
    void Init_00234150();
};
class CFightNodePrevCondition_4a880 {
  public:
    hulk_intptr vtable;
    char pad[0x10 - 4];
    Sub_4a880 sub;
    void Finish_002345b0();
    void Run();
};
struct Node_4a8a0 {
    char pad[0x108];
    int a;
    int b;
};
class Manager_4a8a0 {
  public:
};
class Helper_4a8a0 {
  public:
    Node_4a8a0* Get_00059a30();
};
extern int* hulk_at_004dc570;
class CCondition_4a920 {
  public:
    virtual int vfunc_0(int);
};

} // namespace fn_f901265b

// 0x0004a560 CGrappleAlertStatusCondition::vfunc_8 (56 B): matches/0x0004a560.cpp [wrapped: conflict: CGrappleAlertStatusCondition]
// sym: ?vfunc_8@CGrappleAlertStatusCondition@fn_0004a560@@QAEHH@Z
namespace fn_0004a560 {
// Same code shape as 0x0004a2d0 (propagated; names are from that function)
struct Obj_4a560 {
    char pad[0x330];
    int a;
    int b;
    int c;
};
struct Helper_4a560 {
    Obj_4a560* First_000592a0();
};
struct ObjHelper_4a560 {
    Obj_4a560* Second_00059a30();
};
struct CGrappleAlertStatusCondition {
    int vfunc_8(hulk_intptr);
};
int CGrappleAlertStatusCondition::vfunc_8(hulk_intptr p) {
    if (!p)
        return 0;
    Helper_4a560* h = (Helper_4a560*)p;
    Obj_4a560* x = h->First_000592a0();
    x = ((ObjHelper_4a560*)x)->Second_00059a30();
    if (x->b)
        return x->b;
    if (x->a)
        return x->a;
    return x->c;
}
} // namespace fn_0004a560

namespace fn_f901265b {

// 0x0004a5a0 FUN_0004a5a0 (19 B): matches/0x0004a5a0.cpp
// sym: ?FUN_0004a5a0@fn_f901265b@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0004a5a0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dc540), ((char*)&DAT_004dc544));
}

} // namespace fn_f901265b

// 0x0004a5c0 CRageModeCondition::vfunc_0 (16 B): matches/0x0004a5c0.cpp
// sym: ?vfunc_0@CRageModeCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CRageModeCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc540;
    return p[index];
}


// 0x0004a600 CRageModeCondition::vfunc_7 (44 B): matches/0x0004a600.cpp
// sym: ?vfunc_7@CRageModeCondition@@UAE_NPAX@Z
bool CRageModeCondition::vfunc_7(void* __p0) { void * arg = (void *)__p0;

    A_4a600* a = (A_4a600*)arg;
    void* p = a->Fnf_000592a0();
    B_4a600* b = (B_4a600*)p;
    Manager_4a600* q = (Manager_4a600*)b->Fnf_00059a30();
    bool r = q->field != 0;
    return r == this->f_0c;
}

namespace fn_f901265b {

// 0x0004a630 FUN_0004a630 (19 B): matches/0x0004a630.cpp
// sym: ?FUN_0004a630@fn_f901265b@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0004a630(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dc548), ((char*)&DAT_004dc54c));
}

} // namespace fn_f901265b

// 0x0004a650 CGrappleTimerCondition::vfunc_0 (16 B): matches/0x0004a650.cpp
// sym: ?vfunc_0@CGrappleTimerCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CGrappleTimerCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc548;
    return p[index];
}

namespace fn_f901265b {

// 0x0004a6a0 FUN_0004a6a0 (19 B): matches/0x0004a6a0.cpp
// sym: ?FUN_0004a6a0@fn_f901265b@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0004a6a0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dc550), ((char*)&DAT_004dc554));
}

} // namespace fn_f901265b

// 0x0004a6c0 CInactivityTimerCondition::vfunc_0 (16 B): matches/0x0004a6c0.cpp
// sym: ?vfunc_0@CInactivityTimerCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CInactivityTimerCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc550;
    return p[index];
}


// 0x0004a730 CCharacterFloatCondition::vfunc_0 (16 B): matches/0x0004a730.cpp
// sym: ?vfunc_0@CCharacterFloatCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CCharacterFloatCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc558;
    return p[index];
}


// 0x0004a7a0 CCharacterBoolCondition::vfunc_0 (16 B): matches/0x0004a7a0.cpp
// sym: ?vfunc_0@CCharacterBoolCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CCharacterBoolCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc560;
    return p[index];
}


// 0x0004a7e0 CCharacterBoolCondition::vfunc_7 (54 B): equivalent/0x0004a7e0.cpp [wrapped: conflict: CCharacterBoolCondition]
// sym: ?vfunc_7@CCharacterBoolCondition@fn_0004a7e0@@QAEEPAUContext@2@@Z @3cb6914c6e70 @w1e5cc4d5146b
namespace fn_0004a7e0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// CCharacterBoolCondition::vfunc_7 @ 0x0004a7e0
struct Character;
struct Context {
    Character* FUN_000592a0();
};
struct Character {
    Character* FUN_00059a30();
};
typedef unsigned char (__fastcall *CharacterTest)(Character*);
struct CCharacterBoolCondition {
    char padding[12];
    CharacterTest test;
    int mode;
    unsigned char vfunc_7(Context* context);
};
unsigned char CCharacterBoolCondition::vfunc_7(Context* context) {
    Character* character = context->FUN_000592a0()->FUN_00059a30();
    unsigned char result = test(character);
    if (mode == 1) return result == 0;
    if (mode != 0) return 0;
    return result;
}
} // namespace fn_0004a7e0

namespace fn_f901265b {

// 0x0004a820 FUN_0004a820 (19 B): matches/0x0004a820.cpp
// sym: ?FUN_0004a820@fn_f901265b@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0004a820(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dc568), ((char*)&DAT_004dc56c));
}

} // namespace fn_f901265b

// 0x0004a840 CFightNodePrevCondition::vfunc_0 (16 B): matches/0x0004a840.cpp
// sym: ?vfunc_0@CFightNodePrevCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CFightNodePrevCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc568;
    return p[index];
}

namespace fn_f901265b {

// 0x0004a880 FUN_0004a880 (31 B): matches/0x0004a880.cpp
// sym: ?Run@CFightNodePrevCondition_4a880@fn_f901265b@@QAEXXZ
void CFightNodePrevCondition_4a880::Run() {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f74e0;
    sub.Init_00234150();
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f6d50;
    Finish_002345b0();
}

} // namespace fn_f901265b

// 0x0004a8a0 CFightNodePrevCondition::vfunc_7 (84 B): matches/0x0004a8a0.cpp
// sym: ?vfunc_7@CFightNodePrevCondition@@UAE_NPAX@Z
bool CFightNodePrevCondition::vfunc_7(void* __p0) { void * arg = (void *)__p0;

    Manager_4a8a0* m = (Manager_4a8a0*)arg;
    Node_4a8a0* n = ((Node_4a8a0 *)((owners::Object_592a0 *)m)->FUN_000592a0());
    Node_4a8a0* r = ((Helper_4a8a0*)n)->Get_00059a30();
    int x = r->a;
    if (this->lastFrame == 0)
        x = r->b;
    int y = this->fightNode;
    switch (this->compare) {
    case 0:
        return x == y;
    case 1:
        return x != y;
    }
    return false;
}

namespace fn_f901265b {

// 0x0004a900 FUN_0004a900 (19 B): matches/0x0004a900.cpp
// sym: ?FUN_0004a900@fn_f901265b@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0004a900(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dc570), ((char*)&DAT_004dc574));
}

} // namespace fn_f901265b

// 0x0004a920 CIntentionSpeedCondition::vfunc_0 (16 B): matches/0x0004a920.cpp
// sym: ?vfunc_0@CIntentionSpeedCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CIntentionSpeedCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc570;
    return p[index];
}

namespace fn_f901265b {

// 0x0004a970 FUN_0004a970 (19 B): matches/0x0004a970.cpp
// sym: ?FUN_0004a970@fn_f901265b@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0004a970(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dc578), ((char*)&DAT_004dc57c));
}

} // namespace fn_f901265b
