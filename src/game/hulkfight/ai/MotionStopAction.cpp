// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00115dd0..0x00115e20 (kind game, layer game, confidence medium), dominant class hulkfight::ai::MotionStopAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe5f4a0b {
#define TREE_TU_END }
namespace fn_fe5f4a0b {} using namespace fn_fe5f4a0b;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fe5f4a0b {
class Obj {
  public:
    char* Fnb_00059a30();
};

} // namespace fn_fe5f4a0b

// 0x00115dd0 hulkfight::ai::MotionStopAction::vfunc_5 (71 B): matches/0x00115dd0.cpp
// sym: ?vfunc_5@MotionStopAction@ai@hulkfight@@UAE_NHH@Z
bool hulkfight::ai::MotionStopAction::vfunc_5(hulk_intptr n, int ) {
    if (n == 0) {
        if (!(*(Obj * *)&this->f_20))
            return (bool)(0);
        char* p = ((Obj *)((owners::Object_592a0 *)((*(Obj * *)&this->f_20)))->FUN_000592a0())->Fnb_00059a30() + 0x1f58;
        *(int*)(p + 0x114) = 0;
        *(int*)(p + 0x110) = 0;
        *(int*)(p + 0x10c) = 0;
        *(int*)(p + 0x118) = 0;
    }
    return (bool)(1);
}

