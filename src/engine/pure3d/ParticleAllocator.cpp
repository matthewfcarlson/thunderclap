// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002d3d80..0x002d3dc0 (kind game, layer engine, confidence medium), dominant class pure3d::ParticleAllocator
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f16f11c1 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f16f11c1 {} using namespace fn_f16f11c1;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f16f11c1 {
extern void* hulk_at_003f6098;
extern "C" char DAT_0042f190[];
class ParticleAllocator {
  public:
    hulk_intptr mVptr;
    int mValue;
    ParticleAllocator();
};
class NonCopyable_2d3da0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public NonCopyable_2d3da0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x002d3d80 FUN_002d3d80 (7 B): matches/0x002d3d80.cpp
// sym: ?FUN_002d3d80@fn_f16f11c1@@YIXPAX@Z
// Same code shape as 0x001b6820 (propagated; names are from that function)
void __fastcall FUN_002d3d80(void* self) {
    *(void**)self = &hulk_at_003f6098;
}


// 0x002d3d90 FUN_002d3d90 (16 B): matches/0x002d3d90.cpp
// sym: ??0ParticleAllocator@fn_f16f11c1@@QAE@XZ
ParticleAllocator::ParticleAllocator() {
    mValue = 0;
    mVptr = ((hulk_intptr)DAT_0042f190);
}


// 0x002d3da0 pure3d::ParticleAllocator::vfunc_2 (31 B): matches/0x002d3da0.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f16f11c1@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f16f11c1
