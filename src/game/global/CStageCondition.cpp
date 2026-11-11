// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00048300..0x00048440 (kind game, layer game, confidence medium), dominant class CStageCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f2f736bf {
#define TREE_TU_END }
namespace fn_f2f736bf {} using namespace fn_f2f736bf;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f2f736bf {
extern int* hulk_at_004dc3f8;
class CCondition_48300 {
  public:
    virtual int vfunc_0(int);
};
struct Stage_48350 { char pad[0x1e44]; int value; };
struct Context_48350 { Stage_48350* FUN_00059a30(); };
struct Argument_48350 {  };

} // namespace fn_f2f736bf

// 0x00048300 CStageCondition::vfunc_0 (16 B): matches/0x00048300.cpp
// sym: ?vfunc_0@CStageCondition@@UAEHH@Z
hulk_intptr CStageCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc3f8;
    return p[index];
}


// 0x00048350 CStageCondition::vfunc_7 (168 B): equivalent/0x00048350.cpp
// sym: ?vfunc_7@CStageCondition@@UAE_NPAX@Z @ff4a49d8b26f @w95ce89aef737
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// CStageCondition::vfunc_7 @ 0x00048350
bool CStageCondition::vfunc_7(void* __p0) { Argument_48350 * arg = (Argument_48350 *)__p0;

 Stage_48350* stage = ((Context_48350 *)((owners::Object_592a0 *)arg)->FUN_000592a0())->FUN_00059a30();
 switch((*(unsigned int *)&this->f_0c)) {
 case 0: return stage->value < this->f_10;
 case 1: return stage->value <= this->f_10;
 case 2: return stage->value == this->f_10;
 case 3: return stage->value != this->f_10;
 case 4: return stage->value >= this->f_10;
 case 5: return stage->value > this->f_10;
 default: return false;
 }
}

