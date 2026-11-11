// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0024daa0..0x0024dae0 (kind game, layer engine, confidence medium), dominant class audio::ListenerEffectPs2
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_fc5b0623 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fc5b0623 {} using namespace fn_fc5b0623;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_fc5b0623 {
class ListenerEffectPs2 {
  public:
    virtual void F0();
    virtual void F1();
    virtual ListenerEffectPs2* F2(unsigned char);
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual void F6();
    virtual void F7();
    virtual void F8();
    void Base_00244f70();
};
extern "C" void FUN_00247550(void*, ListenerEffectPs2*);


// 0x0024daa0 audio::ListenerEffectPs2::vfunc_8 (6 B): matches/0x0024daa0.cpp
// sym: _FUN_0024daa0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0024daa0() {
    return &(*(int*)&DAT_004e6548);
}


// 0x0024dab0 audio::ListenerEffectPs2::vfunc_2 (35 B): matches/0x0024dab0.cpp
// sym: ?F2@ListenerEffectPs2@fn_fc5b0623@@UAEPAV12@E@Z
ListenerEffectPs2* ListenerEffectPs2::F2(unsigned char flag) {
    Base_00244f70();
    if (flag & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e6548), this);
    return this;
}

} // namespace fn_fc5b0623
