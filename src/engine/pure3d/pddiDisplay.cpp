// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0031ac80..0x0031acc0 (kind game, layer engine, confidence medium), dominant class pure3d::pddiDisplay
#include "tree_prelude.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fad29cbd {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fad29cbd {} using namespace fn_fad29cbd;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fad29cbd {
extern void* pddiObject_31ac90_vftable[];
class pddiObject_31ac90 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class pddiDisplay_31ac90 : public pddiObject_31ac90 {
  public:
    pddiDisplay_31ac90* vfunc_5(signed char flags);
};

} // namespace fn_fad29cbd

// 0x0031ac80 pure3d::pddiDisplay::vfunc_10 (3 B): matches/0x0031ac80.cpp
// sym: ?vfunc_10@pddiDisplay@pure3d@@UAEEXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
unsigned char pure3d::pddiDisplay::vfunc_10() {
    return 0;
}

namespace fn_fad29cbd {

// 0x0031ac90 pure3d::pddiDisplay::vfunc_3 (36 B): matches/0x0031ac90.cpp
// sym: ?vfunc_5@pddiDisplay_31ac90@fn_fad29cbd@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
pddiDisplay_31ac90* pddiDisplay_31ac90::vfunc_5(signed char flags) {
    *(void***)this = pddiObject_31ac90_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fad29cbd
