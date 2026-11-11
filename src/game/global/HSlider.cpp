// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e2db0..0x000e2ec0 (kind game, layer game, confidence high), dominant class HSlider
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fa446de8 {
#define TREE_TU_END }
namespace fn_fa446de8 {} using namespace fn_fa446de8;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fa446de8 {
struct Other { void FUN_000f9530(int, int, void *); };

} // namespace fn_fa446de8

// 0x000e2db0 HSlider::vfunc_1 (24 B): matches/0x000e2db0.cpp
// sym: ?vfunc_1@HSlider@@UAEXH@Z
void HSlider::vfunc_1(int x) {
    if (x == this->f_180)
        this->f_150 = *(int*)(this->f_180 + 0x40);
}


// 0x000e2dd0 HSlider::vfunc_11 (34 B): matches/0x000e2dd0.cpp
// sym: ?vfunc_11@HSlider@@UAE_NHH@Z
bool HSlider::vfunc_11(int param, int unused) {
    switch (param) {
    case 2:
    case 6:
        this->f_154 = 0;
        return true;
    default:
        return false;
    }
}


// 0x000e2e00 HSlider::vfunc_13 (3 B): matches/0x000e2e00.cpp
// sym: ?vfunc_13@HSlider@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void HSlider::vfunc_13(int a) {
    (void)a;
}


// 0x000e2e10 HSlider::vfunc_14 (13 B): matches/0x000e2e10.cpp
// sym: ?vfunc_14@HSlider@@UAEXH@Z
void HSlider::vfunc_14(int ) {
    this->f_154 = 0;
}


// 0x000e2e20 HSlider::vfunc_6 (41 B): equivalent/0x000e2e20.cpp
// sym: ?vfunc_6@HSlider@@UAEXH@Z @66148ac3e10f @w12d5313ccbc7
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 2/2)
// HSlider::vfunc_6 @ 0x000e2e20
void HSlider::vfunc_6(hulk_intptr __p0) { Other * other = (Other *)__p0;

    if (this->f_90 || this->f_94) {
        other->FUN_000f9530(this->f_90, this->f_94, (*(void * *)&this->f_150));
    }
}


// 0x000e2e50 HSlider::vfunc_9 (7 B): matches/0x000e2e50.cpp
// sym: ?vfunc_9@HSlider@@UAEMXZ
hulk_freg HSlider::vfunc_9() {
    return *(float*)((char*)this + 0x17c);
}

