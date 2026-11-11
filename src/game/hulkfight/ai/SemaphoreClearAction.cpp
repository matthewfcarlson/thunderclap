// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010e350..0x0010e3e0 (kind game, layer game, confidence medium), dominant class hulkfight::ai::SemaphoreClearAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fee95b81 {
#define TREE_TU_END }
namespace fn_fee95b81 {} using namespace fn_fee95b81;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fee95b81 {
struct SemaphoreData {
    char pad[0x18];
    int value;
    char pad2[4];
    char enabled;
    char clearDirectly;
};
struct ClearTarget {
    void FUN_00037000();
};
struct SemaphoreManager {
    ClearTarget* FUN_00059a30();
};
struct SemaphoreSource {
};
struct Owner {
    char pad[0x18];
    int sem;
    char pad2[5];
    char active;
};
class Agent {
  public:
    Agent* Next();
    void Clear();
};

} // namespace fn_fee95b81

// 0x0010e350 hulkfight::ai::SemaphoreClearAction::vfunc_5 (80 B): matches/0x0010e350.cpp
// sym: ?vfunc_5@SemaphoreClearAction@ai@hulkfight@@UAE_NHH@Z
 // namespace hulkfight
bool hulkfight::ai::SemaphoreClearAction::vfunc_5(hulk_intptr , int ) {
    if (!(*(SemaphoreSource * *)&this->f_20))
        return false;
    if ((*(SemaphoreData * *)&this->f_1c)->enabled) {
        ClearTarget* target = ((SemaphoreManager *)((owners::Object_592a0 *)((*(SemaphoreSource * *)&this->f_20)))->FUN_000592a0())->FUN_00059a30();
        if ((*(SemaphoreData * *)&this->f_1c)->clearDirectly) {
            target->FUN_00037000();
            return true;
        }
        ((owners::C_37040 *)target)->FUN_00037040((hulk_intptr)(&(*(SemaphoreData * *)&this->f_1c)->value), 0, 1);
    }
    return true;
}


// 0x0010e3a0 hulkfight::ai::SemaphoreClearAction::vfunc_4 (55 B): matches/0x0010e3a0.cpp
// sym: ?vfunc_4@SemaphoreClearAction@ai@hulkfight@@UAEXXZ
 // namespace hulkfight
void hulkfight::ai::SemaphoreClearAction::vfunc_4() {
    if ((*(Agent * *)&this->f_20)) {
        Agent* a = ((Agent *)((owners::Object_592a0 *)((*(Agent * *)&this->f_20)))->FUN_000592a0())->Next();
        Owner* o = (*(Owner * *)&this->f_1c);
        if (o->active) {
            a->Clear();
            return;
        }
        ((owners::C_37040 *)a)->FUN_00037040((hulk_intptr)(Owner *)((Owner*)((char*)o + 0x18)), 0, 1);
    }
}

