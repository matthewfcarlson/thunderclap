// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00172790..0x001727f0 (kind game, layer game, confidence medium), dominant class hulkfight::motion::CriticalMassDrainAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f1d496c3 {
#define TREE_TU_END }
namespace fn_f1d496c3 {} using namespace fn_f1d496c3;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f1d496c3 {
struct Obj_172790 {
    char pad[0x1b0c];
    float amount;
    float Get();
    void Set(float, int);
};
struct Mid_172790 {
    Obj_172790* GetObj();
};
struct Source_172790 {
};
struct Param_172790 {
    char pad[0x10];
    float amount;
};

} // namespace fn_f1d496c3

// 0x00172790 hulkfight::motion::CriticalMassDrainAction::vfunc_3 (93 B): matches/0x00172790.cpp
// sym: ?vfunc_3@CriticalMassDrainAction@motion@hulkfight@@UAE_NHH@Z
 // namespace hulkfight
bool hulkfight::motion::CriticalMassDrainAction::vfunc_3(hulk_intptr x, hulk_intptr y) {
    if (!(*(Source_172790 * *)&this->f_20))
        return (bool)(0);
    Mid_172790* m = ((Mid_172790 *)((owners::Object_592a0 *)((*(Source_172790 * *)&this->f_20)))->FUN_000592a0());
    if (!m)
        return (bool)(0);
    Obj_172790* o = m->GetObj();
    if (!o)
        return (bool)(0);
    hulk_freg amt = o->amount;
    if (amt >= o->Get())
        o->Set(amt - (*(Param_172790 * *)&this->f_1c)->amount, 1);
    return (bool)(0);
}

