// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00326d60..0x00326dc0 (kind game, layer engine, confidence high), dominant class pure3d::pddiPrimBuffer
#include "tree_prelude.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_ff39715a {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_ff39715a {} using namespace fn_ff39715a;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_ff39715a {
extern void* pddiObject_326d90_vftable[];
class pddiObject_326d90 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class pddiPrimBuffer_326d90 : public pddiObject_326d90 {
  public:
    pddiPrimBuffer_326d90* vfunc_5(signed char flags);
};


// 0x00326d60 pure3d::pddiPrimBuffer::vfunc_6 (1 B): matches/0x00326d60.cpp
// sym: ?FUN_00326d60@fn_ff39715a@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00326d60() {}

} // namespace fn_ff39715a

// 0x00326d70 pure3d::pddiPrimBuffer::vfunc_13 (3 B): matches/0x00326d70.cpp
// sym: ?vfunc_13@pddiPrimBuffer@pure3d@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void pure3d::pddiPrimBuffer::vfunc_13(int a, int b) {}


// 0x00326d80 pure3d::pddiPrimBuffer::vfunc_14 (3 B): matches/0x00326d80.cpp
// sym: ?vfunc_14@pddiPrimBuffer@pure3d@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void pure3d::pddiPrimBuffer::vfunc_14(int a) {
    (void)a;
}

namespace fn_ff39715a {

// 0x00326d90 pure3d::pddiPrimBuffer::vfunc_3 (36 B): matches/0x00326d90.cpp
// sym: ?vfunc_5@pddiPrimBuffer_326d90@fn_ff39715a@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
pddiPrimBuffer_326d90* pddiPrimBuffer_326d90::vfunc_5(signed char flags) {
    *(void***)this = pddiObject_326d90_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_ff39715a
