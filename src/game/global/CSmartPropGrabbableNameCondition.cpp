// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00049740..0x00049990 (kind game, layer game, confidence medium), dominant class CSmartPropGrabbableNameCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fd51c33d {
#define TREE_TU_END }
namespace fn_fd51c33d {} using namespace fn_fd51c33d;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fd51c33d {
extern int* hulk_at_004dc4c8;
class CCondition_49760 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc4d0;
class CCondition_497d0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc4d8;
class CCondition_49860 {
  public:
    virtual int vfunc_0(int);
};


// 0x00049740 FUN_00049740 (19 B): matches/0x00049740.cpp
// sym: ?FUN_00049740@fn_fd51c33d@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00049740(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dc4c8), ((char*)&DAT_004dc4cc));
}

} // namespace fn_fd51c33d

// 0x00049760 CSmartPropAngleCondition::vfunc_0 (16 B): matches/0x00049760.cpp
// sym: ?vfunc_0@CSmartPropAngleCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CSmartPropAngleCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc4c8;
    return p[index];
}

namespace fn_fd51c33d {

// 0x000497b0 FUN_000497b0 (19 B): matches/0x000497b0.cpp
// sym: ?FUN_000497b0@fn_fd51c33d@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_000497b0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dc4d0), ((char*)&DAT_004dc4d4));
}

} // namespace fn_fd51c33d

// 0x000497d0 CSmartPropDistanceCondition::vfunc_0 (16 B): matches/0x000497d0.cpp
// sym: ?vfunc_0@CSmartPropDistanceCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CSmartPropDistanceCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc4d0;
    return p[index];
}


// 0x00049820 FUN_00049820 (31 B): matches/0x00049820.cpp [wrapped: conflict: CSmartPropDistanceCondition]
// sym: ?Build@CSmartPropDistanceCondition@fn_00049820@@QAEXXZ
namespace fn_00049820 {
extern int hulk_at_003f71e4;
extern int hulk_at_003f6d50;
class CSmartPropDistanceCondition {
  public:
    virtual void V0();
    char pad[0x18 - 4];
    class Part {
      public:
        void Init_0027af50();
    } part;
    void Final_002345b0();
    void Build();
};
void CSmartPropDistanceCondition::Build() {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f71e4;
    part.Init_0027af50();
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f6d50;
    Final_002345b0();
}
} // namespace fn_00049820

namespace fn_fd51c33d {

// 0x00049840 FUN_00049840 (19 B): matches/0x00049840.cpp
// sym: ?FUN_00049840@fn_fd51c33d@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00049840(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dc4d8), ((char*)&DAT_004dc4dc));
}

} // namespace fn_fd51c33d

// 0x00049860 CSmartPropGrabbableNameCondition::vfunc_0 (16 B): matches/0x00049860.cpp
// sym: ?vfunc_0@CSmartPropGrabbableNameCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CSmartPropGrabbableNameCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc4d8;
    return p[index];
}


// 0x000498a0 FUN_000498a0 (31 B): matches/0x000498a0.cpp [wrapped: conflict: CCondition]
// sym: ?Run@CSmartPropGrabbableNameCondition_498a0@fn_000498a0@@QAEXXZ
namespace fn_000498a0 {
// Same code shape as 0x0004a030 (propagated; names are from that function)
extern int hulk_at_003f7208;
extern int vtableB;
class Part_498a0 {
  public:
    void Init_0027af50();
};
class CCondition {
  public:
    virtual void F();
};
class CSmartPropGrabbableNameCondition_498a0 : public CCondition {
  public:
    char pad[12];
    Part_498a0 part;
    void Run();
    void Finish_002345b0();
};
void CSmartPropGrabbableNameCondition_498a0::Run() {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f7208;
    part.Init_0027af50();
    *(hulk_intptr*)this = (hulk_intptr)&vtableB;
    Finish_002345b0();
}
} // namespace fn_000498a0


// 0x000498c0 CSmartPropGrabbableNameCondition::vfunc_7 (193 B): equivalent/0x000498c0.cpp [wrapped: conflict: CSmartPropGrabbableNameCondition]
// sym: ?vfunc_7@CSmartPropGrabbableNameCondition@fn_000498c0@@UAE_NPAUContext@2@@Z @d72cf804513f @w45efc3ad51d9
namespace fn_000498c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3052 inputs, branch coverage 28/28)
// CSmartPropGrabbableNameCondition::vfunc_7 @ 0x000498c0
struct NameSource_498c0 { char pad[8]; unsigned low, high; unsigned __int64 FUN_001d4f70(); };
struct Object { char pad[0xec]; NameSource_498c0* name; };
struct Prop_498c0 { char pad[8]; Object* object; unsigned type; };
struct Actor_498c0 { char pad[0x3a4]; Prop_498c0* prop; };
struct ContextInner_498c0 { Actor_498c0* FUN_00059a30(); };
struct Context { ContextInner_498c0* FUN_000592a0(); void FUN_00059790(Prop_498c0*); };
struct CSmartPropGrabbableNameCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual bool vfunc_7(Context*);
 char pad[8]; unsigned mode; unsigned low, high;
};
bool CSmartPropGrabbableNameCondition::vfunc_7(Context* context) {
 if (!(low | high)) return false;
 Prop_498c0* prop = context->FUN_000592a0()->FUN_00059a30()->prop;
 if (!prop || prop->type != 5 || !prop->object) return false;
 if (mode > 1) return false;
 unsigned m = mode;
 NameSource_498c0* source = prop->object->name;
 unsigned l = low, h = high;
 bool equal = source->low == l && source->high == h;
 if (!equal) { unsigned __int64 n = source->FUN_001d4f70(); equal = (unsigned)n == l && (unsigned)(n >> 32) == h; }
 if (equal == (m == 0)) { context->FUN_00059790(prop); return true; }
 return false;
}
} // namespace fn_000498c0

