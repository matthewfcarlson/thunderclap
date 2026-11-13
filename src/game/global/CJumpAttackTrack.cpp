// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006a5a0..0x0006a680 (kind game, layer game, confidence high), dominant class CJumpAttackTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fddc6665 {
#define TREE_TU_END }
namespace fn_fddc6665 {} using namespace fn_fddc6665;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fddc6665 {
struct Param_6a630 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_6a630 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
class Alloc_6a650 {
  public:
    int method_0001f980(CJumpAttackTrack*, hulk_intptr);
};
extern "C" Alloc_6a650* FUN_0008d690(int);


// 0x0006a5a0 FUN_0006a5a0 (19 B): matches/0x0006a5a0.cpp
// sym: ?FUN_0006a5a0@fn_fddc6665@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0006a5a0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dcfb8), ((char*)&DAT_004dcfbc));
}


// 0x0006a5c0 CJumpAttackTrack::vfunc_0 (16 B): matches/0x0006a5c0.cpp
// sym: _FUN_0006a5c0@4
// data: g_table_6a5c0 = DAT_004dcfb8
extern "C" int __stdcall FUN_0006a5c0(int a1) {
    return (*(int**)&DAT_004dcfb8)[a1];
}

} // namespace fn_fddc6665

// 0x0006a5d0 FUN_0006a5d0 (67 B): equivalent/0x0006a5d0.cpp [wrapped: conflict: CJumpAttackTrack]
// sym: ??0CJumpAttackTrack@fn_0006a5d0@@QAE@XZ @872e5a09578f @w0d921f87ed66
namespace fn_0006a5d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0006a5d0 @ 0x0006a5d0
struct FUN_00236d40 { FUN_00236d40(); virtual void unused(); }; struct CJumpAttackTrack : FUN_00236d40 { char pad[8]; float a; float b; float c; float d; float e; float f; float g; float h; float i; float j; float k; CJumpAttackTrack(); }; CJumpAttackTrack::CJumpAttackTrack() { a=0.0f; b=-1.0f; c=0.0f; d=-1.0f; e=-1.0f; f=1.57079637f; g=10.0f; h=10.0f; i=0.0f; j=0.0f; k=0.0f; }
} // namespace fn_0006a5d0


// 0x0006a620 CJumpAttackTrack::vfunc_6 (4 B): matches/0x0006a620.cpp
// sym: ?vfunc_6@CJumpAttackTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CJumpAttackTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0006a630 CJumpAttackTrack::vfunc_7 (7 B): matches/0x0006a630.cpp
// sym: ?vfunc_7@CJumpAttackTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CJumpAttackTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x0006a650 CJumpAttackTrack::vfunc_12 (40 B): matches/0x0006a650.cpp
// sym: ?vfunc_12@CJumpAttackTrack@@UAEHH@Z
hulk_intptr CJumpAttackTrack::vfunc_12(hulk_intptr param) {
    Alloc_6a650* p = FUN_0008d690(0x34);
    if (p)
        return p->method_0001f980(this, param);
    return 0;
}

