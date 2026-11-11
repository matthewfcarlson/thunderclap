// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00049990..0x00049b40 (kind game, layer game, confidence medium), dominant class CSmartPropStateCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa7ecd1e {
#define TREE_TU_END }
namespace fn_fa7ecd1e {} using namespace fn_fa7ecd1e;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fa7ecd1e {
extern int* hulk_at_004dc4e0;
class CCondition_499b0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc4e8;
class CCondition_49a10 {
  public:
    virtual int vfunc_0(int);
};
struct State_49a60 { char pad[0x40]; int value; };
struct Link_49a60 { char pad[8]; State_49a60* state; int type; };
struct Actor_49a60 { char pad[0x3a4]; Link_49a60* link;  };
struct Owner_49a60 { Actor_49a60* FUN_00059a30(); };
struct Context_49a60 {  };


// 0x00049990 FUN_00049990 (19 B): matches/0x00049990.cpp
// sym: ?FUN_00049990@fn_fa7ecd1e@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00049990() {
    FUN_00234810(((char*)&DAT_004dc4e0), ((char*)&DAT_004dc4e4));
}

} // namespace fn_fa7ecd1e

// 0x000499b0 CSmartPropCSMableCondition::vfunc_0 (16 B): matches/0x000499b0.cpp
// sym: ?vfunc_0@CSmartPropCSMableCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CSmartPropCSMableCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc4e0;
    return p[index];
}

namespace fn_fa7ecd1e {

// 0x000499f0 FUN_000499f0 (19 B): matches/0x000499f0.cpp
// sym: ?FUN_000499f0@fn_fa7ecd1e@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_000499f0() {
    FUN_00234810(((char*)&DAT_004dc4e8), ((char*)&DAT_004dc4ec));
}

} // namespace fn_fa7ecd1e

// 0x00049a10 CSmartPropStateCondition::vfunc_0 (16 B): matches/0x00049a10.cpp
// sym: ?vfunc_0@CSmartPropStateCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CSmartPropStateCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc4e8;
    return p[index];
}


// 0x00049a60 CSmartPropStateCondition::vfunc_7 (189 B): equivalent/0x00049a60.cpp
// sym: ?vfunc_7@CSmartPropStateCondition@@UAE_NPAX@Z @d4a2bef710a9 @w3be70fabfa7c
// STATUS: equivalent (tools/equiv.py level 3: 3021 inputs, branch coverage 28/28)
// CSmartPropStateCondition::vfunc_7 @ 0x00049a60
bool CSmartPropStateCondition::vfunc_7(void* __p0) { Context_49a60 * context = (Context_49a60 *)__p0;

 Actor_49a60* actor = ((Owner_49a60 *)((owners::Object_592a0 *)context)->FUN_000592a0())->FUN_00059a30();
 State_49a60* state = ((State_49a60 *)((owners::C_35ef0 *)actor)->FUN_00035ef0((hulk_intptr)0));
 if (!state) {
  Link_49a60* link = actor->link;
  if (!link || link->type != 5) return false;
  state = link->state;
  if (!state) return false;
 }
 int value = state->value;
 switch ((*(unsigned int *)&this->f_0c)) {
 case 0: return value < this->f_10;
 case 1: return value <= this->f_10;
 case 2: return value == this->f_10;
 case 3: return value != this->f_10;
 case 4: return value >= this->f_10;
 case 5: return value > this->f_10;
 default: return false;
 }
}

