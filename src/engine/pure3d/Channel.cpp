// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0028b910..0x0028b970 (kind game, layer engine, confidence medium), dominant class pure3d::Channel
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_ffd25c71 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ffd25c71 {} using namespace fn_ffd25c71;
namespace fn_ffd25c71 { extern "C" char DAT_0042c920[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_ffd25c71 {
extern "C" char DAT_0042c95c[];
class IRefCount {
  public:
    virtual void _m_vf0();
    virtual void Release();
    virtual void f2();
};
class ChannelLoader {
  public:
    hulk_intptr vf;
    int pad;
    int count;
    IRefCount* items[1];
    void cleanup();
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


// 0x0028b910 FUN_0028b910 (61 B): matches/0x0028b910.cpp
// sym: ?cleanup@ChannelLoader@fn_ffd25c71@@QAEXXZ
void ChannelLoader::cleanup() {
    vf = ((hulk_intptr)DAT_0042c95c);
    for (int i = 0; i < count; ++i) {
        if (items[i]) {
            items[i]->Release();
            items[i] = 0;
        }
    }
    vf = ((hulk_intptr)DAT_003f6098);
}


// 0x0028b950 pure3d::Channel::vfunc_0 (31 B): matches/0x0028b950.cpp
// sym: ?f2@NonCopyable@pure3d@fn_ffd25c71@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_0042c920;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_ffd25c71
