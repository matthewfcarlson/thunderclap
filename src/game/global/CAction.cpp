// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00013940..0x000139b0 (kind game, layer game, confidence high), dominant class CAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f83f3e09 {
#define TREE_TU_END }
namespace fn_f83f3e09 {} using namespace fn_f83f3e09;
#include "game/global.h"


// 0x00013940 CAction::vfunc_3 (13 B): matches/0x00013940.cpp
// sym: ?vfunc_3@CAction@@UAE_NHH@Z
bool CAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    return (bool)(vfunc_6(b));
}


// 0x00013950 CAction::vfunc_5 (40 B): matches/0x00013950.cpp
// sym: ?vfunc_5@CAction@@UAE_NHH@Z
bool CAction::vfunc_5(hulk_intptr sel, int arg) {
    bool r = false;
    switch (sel) {
    case 0:
        r = vfunc_7(arg);
        break;
    case 1:
        r = vfunc_8(arg);
        break;
    }
    return r;
}


// 0x00013980 CAction::vfunc_6 (5 B): matches/0x00013980.cpp
// sym: ?vfunc_6@CAction@@UAE_NH@Z
bool CAction::vfunc_6(int __p0) {
    return true;
}


// 0x00013990 CAction::vfunc_7 (5 B): matches/0x00013990.cpp
// sym: ?vfunc_7@CAction@@UAE_NH@Z
// Same code shape as 0x00013980 (propagated; names are from that function)
bool CAction::vfunc_7(int __p0) {
    return true;
}


// 0x000139a0 CAction::vfunc_8 (5 B): matches/0x000139a0.cpp
// sym: ?vfunc_8@CAction@@UAE_NH@Z
// Same code shape as 0x00013980 (propagated; names are from that function)
bool CAction::vfunc_8(int __p0) {
    return true;
}

