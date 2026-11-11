// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0024dca0..0x0024dce0 (kind game, layer engine, confidence medium), dominant class audio::ListenerEffectPsp
#include "tree_prelude.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_fe3f50f1 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fe3f50f1 {} using namespace fn_fe3f50f1;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_fe3f50f1 {
namespace audio {
class ListenerEffectPsp {
  public:
    virtual void f0();
    virtual void f1();
    virtual ListenerEffectPsp* vfunc_2(int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
};
}
extern void __fastcall FUN_00244f70(audio::ListenerEffectPsp*);
extern "C" void FUN_00247550(void*, audio::ListenerEffectPsp*);


// 0x0024dca0 audio::ListenerEffectPsp::vfunc_8 (6 B): matches/0x0024dca0.cpp
// sym: _FUN_0024dca0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0024dca0() {
    return &(*(int*)&DAT_004e6628);
}


// 0x0024dcb0 audio::ListenerEffectPsp::vfunc_2 (35 B): matches/0x0024dcb0.cpp
// sym: ?vfunc_2@ListenerEffectPsp@audio@fn_fe3f50f1@@UAEPAV123@H@Z
audio::ListenerEffectPsp* audio::ListenerEffectPsp::vfunc_2(int x) {
    FUN_00244f70(this);
    if (x & 1)
        FUN_00247550(((char*)&DAT_004e6628), this);
    return this;
}

} // namespace fn_fe3f50f1
