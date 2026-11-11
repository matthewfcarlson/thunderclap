// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0024dba0..0x0024dbe0 (kind game, layer engine, confidence medium), dominant class audio::ListenerEffectWin32
#include "tree_prelude.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_f79c238c {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f79c238c {} using namespace fn_f79c238c;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f79c238c {
extern "C" void FUN_00247550(const void*, void*);
namespace audio {
class ListenerEffectWin32 {
  public:
    virtual void a();
    virtual void b();
    virtual ListenerEffectWin32* vfunc_2(int);
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    void BaseCall_00244f70();
};
}


// 0x0024dba0 audio::ListenerEffectWin32::vfunc_8 (6 B): matches/0x0024dba0.cpp
// sym: _FUN_0024dba0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0024dba0() {
    return &(*(int*)&DAT_004e65b8);
}


// 0x0024dbb0 audio::ListenerEffectWin32::vfunc_2 (35 B): matches/0x0024dbb0.cpp
// sym: ?vfunc_2@ListenerEffectWin32@audio@fn_f79c238c@@UAEPAV123@H@Z
// data: gBss_24dbb0 = DAT_004e65b8
audio::ListenerEffectWin32* audio::ListenerEffectWin32::vfunc_2(int flag) {
    BaseCall_00244f70();
    if (flag & 1)
        FUN_00247550(((int*)&DAT_004e65b8), this);
    return this;
}

} // namespace fn_f79c238c
