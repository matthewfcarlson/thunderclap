// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00325ee0..0x00325f30 (kind game, layer engine, confidence high), dominant class pure3d::pddiTexture
#include "tree_prelude.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f93b2b86 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f93b2b86 {} using namespace fn_f93b2b86;
namespace fn_f93b2b86 { extern "C" char DAT_00433354[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f93b2b86 {
extern void* pddiObject_325f00_vftable[];
class pddiObject_325f00 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class pddiTexture_325f00 : public pddiObject_325f00 {
  public:
    pddiTexture_325f00* vfunc_5(signed char flags);
};

} // namespace fn_f93b2b86

// 0x00325ee0 pure3d::pddiTexture::vfunc_15 (3 B): matches/0x00325ee0.cpp
// sym: ?vfunc_15@pddiTexture@pure3d@@UAEXHHH@Z
// Same code shape as 0x00098430 (propagated; names are from that function)
void pure3d::pddiTexture::vfunc_15(int , int , int ) {}


// 0x00325ef0 pure3d::pddiTexture::vfunc_20 (3 B): matches/0x00325ef0.cpp
// sym: ?vfunc_20@pddiTexture@pure3d@@UAEXHHHHHHH@Z
// Same code shape as 0x0030cc90 (propagated; names are from that function)
void pure3d::pddiTexture::vfunc_20(int , int , int , int , int , int , int ) {}

namespace fn_f93b2b86 {

// 0x00325f00 pure3d::pddiTexture::vfunc_3 (36 B): matches/0x00325f00.cpp
// sym: ?vfunc_5@pddiTexture_325f00@fn_f93b2b86@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
pddiTexture_325f00* pddiTexture_325f00::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_00433354);
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f93b2b86
