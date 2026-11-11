// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00016cb0..0x00016d30 (kind game, layer game, confidence medium), dominant class CEffectStopAction
#include "tree_prelude.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f2d01c9c {
#define TREE_TU_END }
namespace fn_f2d01c9c {} using namespace fn_f2d01c9c;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f2d01c9c {
class A_16cc0 {
  public:
};
class B_16cc0 {
  public:
    void Put(int);
};
class A2 {
  public:
    A_16cc0* Second();
};
class M_16cc0 {
  public:
};
extern "C" B_16cc0* __cdecl FUN_0027f250();

} // namespace fn_f2d01c9c

// 0x00016cb0 CEffectStopAction::vfunc_6 (5 B): matches/0x00016cb0.cpp
// sym: ?vfunc_6@CEffectStopAction@@UAE_NH@Z
// Same code shape as 0x00013980 (propagated; names are from that function)
bool CEffectStopAction::vfunc_6(int __p0) {
    return true;
}


// 0x00016cc0 CEffectStopAction::vfunc_4 (103 B): matches/0x00016cc0.cpp
// sym: ?vfunc_4@CEffectStopAction@@UAEXXZ
void CEffectStopAction::vfunc_4() {
    A2* q = ((A2 *)((owners::Object_592a0 *)((*(M_16cc0 * *)&this->f_1c)))->FUN_000592a0());
    A_16cc0* a = q->Second();
    B_16cc0* c = FUN_0027f250();
    int lo = (*(int * *)&this->f_20)[4];
    int hi = (*(int * *)&this->f_20)[5];
    if (lo < 0 || hi <= lo || hi >= 32) {
        int v = ((int)((owners::C_36c60 *)a)->FUN_00036c60((unsigned int)lo));
        c->Put(v);
        return;
    }
    while (lo <= hi) {
        int v = ((int)((owners::C_36c60 *)a)->FUN_00036c60((unsigned int)lo));
        c->Put(v);
        ++lo;
    }
}

