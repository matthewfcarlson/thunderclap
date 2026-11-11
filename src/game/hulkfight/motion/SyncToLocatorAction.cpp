// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00171e60..0x001721f0 (kind game, layer game, confidence medium), dominant class hulkfight::motion::SyncToLocatorAction
#include "tree_prelude.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fcf6ea5c {
#define TREE_TU_END }
namespace fn_fcf6ea5c {} using namespace fn_fcf6ea5c;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fcf6ea5c {
struct C3_1721c0 {
    void Apply(void* p, int f);
};
struct C2_1721c0 {
    C3_1721c0* Get2();
};
struct C1_1721c0 {
};

} // namespace fn_fcf6ea5c

// 0x001721c0 hulkfight::motion::SyncToLocatorAction::vfunc_4 (37 B): matches/0x001721c0.cpp
// sym: ?vfunc_4@SyncToLocatorAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::SyncToLocatorAction::vfunc_4() {
    C2_1721c0* a = ((C2_1721c0 *)((owners::Object_592a0 *)((*(C1_1721c0 * *)&this->f_20)))->FUN_000592a0());
    C3_1721c0* b = a->Get2();
    if (b)
        b->Apply((*(void * *)&this->f_30), 0);
}

