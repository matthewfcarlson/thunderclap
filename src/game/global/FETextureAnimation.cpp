// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x000f11f0..0x000f1250 (kind game, layer game, confidence medium), dominant class FETextureAnimation
#include "tree_prelude.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_ff1486cd {
#define TREE_TU_END }
namespace fn_ff1486cd {} using namespace fn_ff1486cd;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ff1486cd {
extern void* hulk_at_0040c3d0[];
class Ref_f11f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class FEPoseAnimation_f11f0 {
  public:
    void* vptr;
    void Fin_000e8730();
};
void Free_0008d330(void*) throw();
struct Sub_f11f0 {
    char c;
};
void __fastcall SubFini(Sub_f11f0*) throw();
void __fastcall SubFini2(Sub_f11f0*) throw();
void __fastcall SubFini3(Sub_f11f0*) throw();
class FEParticleAnimation_f11f0 : public FEPoseAnimation_f11f0 {
  public:
    char p64[96];
    Ref_f11f0* m64;
    FEParticleAnimation_f11f0* f(unsigned char fl);
};


// 0x000f11f0 FEParticleAnimation::vfunc_0 (57 B): matches/0x000f11f0.cpp
// sym: ?f@FEParticleAnimation_f11f0@fn_ff1486cd@@QAEPAV12@E@Z
FEParticleAnimation_f11f0* FEParticleAnimation_f11f0::f(unsigned char fl) {
    vptr = hulk_at_0040c3d0;
    _ReadWriteBarrier();
    if (m64) {
        m64->Release();
        m64 = 0;
    }
    Fin_000e8730();
    if (fl & 1)
        Free_0008d330(this);
    return this;
}

} // namespace fn_ff1486cd

// 0x000f1230 FETextureAnimation::vfunc_0 (30 B): matches/0x000f1230.cpp
// sym: ??_GFETextureAnimation@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
FETextureAnimation::~FETextureAnimation() {}

