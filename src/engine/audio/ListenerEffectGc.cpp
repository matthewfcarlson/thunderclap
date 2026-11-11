// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0024d9a0..0x0024d9e0 (kind game, layer engine, confidence medium), dominant class audio::ListenerEffectGc
#include "tree_prelude.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_f72fbc17 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f72fbc17 {} using namespace fn_f72fbc17;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f72fbc17 {
namespace audio {
class ListenerEffectGc {
  public:
    virtual void f0();
    virtual void f1();
    virtual ListenerEffectGc* vfunc_2(int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
};
}
struct ThisCall_00244f70 {
    void FUN_00244f70();
};
extern "C" void FUN_00247550(void*, void*);


// 0x0024d9a0 audio::ListenerEffectGc::vfunc_8 (6 B): matches/0x0024d9a0.cpp
// sym: _FUN_0024d9a0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0024d9a0() {
    return &(*(int*)&DAT_004e64d8);
}


// 0x0024d9b0 audio::ListenerEffectGc::vfunc_2 (35 B): matches/0x0024d9b0.cpp
// sym: ?vfunc_2@ListenerEffectGc@audio@fn_f72fbc17@@UAEPAV123@H@Z
audio::ListenerEffectGc* audio::ListenerEffectGc::vfunc_2(int flags) {
    ((ThisCall_00244f70*)(this))->FUN_00244f70();
    if (flags & 1)
        FUN_00247550(((char*)&DAT_004e64d8), this);
    return this;
}

} // namespace fn_f72fbc17
