// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001719c0..0x00171a20 (kind game, layer game, confidence medium), dominant class hulkfight::motion::ChargeClearAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f46d7401 {
#define TREE_TU_END }
namespace fn_f46d7401 {} using namespace fn_f46d7401;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f46d7401 {
class HelperB_1719c0 {
  public:
    void* run_00059a30();
};
class HelperA_1719c0 {
  public:
    HelperB_1719c0* run_000592a0();
};
struct State_1719c0 {
    char pad[0x14];
    unsigned char active;
};
struct A_1719f0 {
    char pad[0x14];
    unsigned char flag;
};
struct B_1719f0 {
    char pad[0x1e58];
    int value;
};
struct First_1719f0 {
};
struct Second_1719f0 {
    B_1719f0* Fng_00059a30();
};

} // namespace fn_f46d7401

// 0x001719c0 hulkfight::motion::ChargeClearAction::vfunc_3 (45 B): matches/0x001719c0.cpp
// sym: ?vfunc_3@ChargeClearAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::ChargeClearAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    if (((State_1719c0*)(*(void * *)&this->f_1c))->active) {
        HelperB_1719c0* x = (*(HelperA_1719c0 * *)&this->f_20)->run_000592a0();
        void* result = x->run_00059a30();
        *(int*)((char*)result + 0x1e58) = 0;
        return (bool)(0);
    }
    return (bool)(1);
}


// 0x001719f0 hulkfight::motion::ChargeClearAction::vfunc_4 (36 B): matches/0x001719f0.cpp
// sym: ?vfunc_4@ChargeClearAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::ChargeClearAction::vfunc_4() {
    if (!((A_1719f0*)(*(void * *)&this->f_1c))->flag) {
        B_1719f0* x = ((B_1719f0 *)((owners::Object_592a0 *)(((First_1719f0*)(*(void * *)&this->f_20))))->FUN_000592a0());
        B_1719f0* y = ((Second_1719f0*)x)->Fng_00059a30();
        y->value = 0;
    }
}

