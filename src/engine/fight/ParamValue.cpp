// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002352d0..0x00235300 (kind game, layer engine, confidence medium), dominant class fight::ParamValue
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f5a13b5b {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f5a13b5b {} using namespace fn_f5a13b5b;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f5a13b5b {
class Part_2352d0 {
  public:
    void Init_0027af50();
};
namespace fight {
class ParamValue {
  public:
    hulk_intptr vt;
    int pad;
    Part_2352d0 part;
    ParamValue* vfunc_0(int);
};
}
extern "C" void __cdecl thunk_FUN_00267090(fight::ParamValue*);


// 0x002352d0 fight::ParamValue::vfunc_0 (39 B): matches/0x002352d0.cpp
// sym: ?vfunc_0@ParamValue@fight@fn_f5a13b5b@@QAEPAV123@H@Z
// Same code shape as 0x00235300 (propagated; names are from that function)
fight::ParamValue* fight::ParamValue::vfunc_0(int flag) {
    vt = (hulk_intptr)&base_vtable;
    part.Init_0027af50();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f5a13b5b
