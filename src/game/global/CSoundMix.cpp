// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001e85c0..0x001e8710 (kind game, layer game, confidence high), dominant class CSoundMix
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f9b4d5ee {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9b4d5ee {} using namespace fn_f9b4d5ee;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f9b4d5ee {
extern int v_1e85c0[];
class Stream {
  public:
    void Init();
};
class CSoundMix {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int);
    int mRefCount;
};
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x001e85c0 FUN_001e85c0 (7 B): matches/0x001e85c0.cpp
// sym: ?Init@Stream@fn_f9b4d5ee@@QAEXXZ
void Stream::Init() {
    *(hulk_intptr*)this = (hulk_intptr)v_1e85c0;
}


// 0x001e86c0 CSoundMix::vfunc_1 (13 B): matches/0x001e86c0.cpp
// sym: ?vfunc_1@CSoundMix@fn_f9b4d5ee@@UAEXXZ
void CSoundMix::vfunc_1() {
    if (--mRefCount == 0)
        vfunc_2(1);
}


// 0x001e86d0 CSoundMix::vfunc_2 (31 B): matches/0x001e86d0.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f9b4d5ee@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f9b4d5ee
