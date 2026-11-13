// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x003278e0..0x00327910 (kind game, layer engine, confidence medium), dominant class pure3d::pddiShader
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f8e4d6d5 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f8e4d6d5 {} using namespace fn_f8e4d6d5;
namespace fn_f8e4d6d5 {
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
namespace fn_f8e4d6d5 { extern "C" char DAT_00433568[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f8e4d6d5 {
extern void* pddiObject_3278e0_vftable[];
class pddiObject_3278e0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class pddiShader_3278e0 : public pddiObject_3278e0 {
  public:
    pddiShader_3278e0* vfunc_5(signed char flags);
};


// 0x003278e0 pure3d::pddiShader::vfunc_3 (36 B): matches/0x003278e0.cpp
// sym: ?vfunc_5@pddiShader_3278e0@fn_f8e4d6d5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
pddiShader_3278e0* pddiShader_3278e0::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_00433568);
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}

} // namespace fn_f8e4d6d5
