// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0024d9e0..0x0024daa0 (kind game, layer engine, confidence medium), dominant class audio::ListenerEffectPs2Type
#include "tree_prelude.h"
#include "decls/address.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#define TREE_TU_BEGIN namespace fn_f56426cf {
#define TREE_TU_END }
namespace fn_f56426cf {} using namespace fn_f56426cf;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f56426cf {
typedef unsigned __int64 U64_24d9e0;
class FUN_0025e6c0 {
  public:
    virtual void f();
    FUN_0025e6c0(const U64_24d9e0*, const U64_24d9e0*, int, int, int);
};
class ListenerEffectPs2Type : public FUN_0025e6c0 {
  public:
    virtual void f();
    ListenerEffectPs2Type();
};
} // namespace fn_f56426cf
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f56426cf {
struct Factory;
struct ListenerEffectPs2_24da50 {
    virtual void vfunc_0_00243360();
    virtual void vfunc_1_00243370();
    virtual void vfunc_2();
    virtual void vfunc_3();
    void FUN_0025e6f0(Factory*);
};
struct Factory {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual ListenerEffectPs2_24da50* vfunc_3();
};
extern "C" ListenerEffectPs2_24da50* __cdecl FUN_00247530(Factory*);
struct Returned { void FUN_0025fb00(ListenerEffectPs2_24da50*); };


// 0x0024d9e0 FUN_0024d9e0 (92 B): matches/0x0024d9e0.cpp
// sym: ??0ListenerEffectPs2Type@fn_f56426cf@@QAE@XZ
ListenerEffectPs2Type::ListenerEffectPs2Type()
    : FUN_0025e6c0(&(const U64_24d9e0&)FUN_002672f0("Data_Effect", 0, 0), &(const U64_24d9e0&)FUN_002672f0("ListenerEffectPs2", 0, 0), 0x1000101, 0x38, 8) {}


// 0x0024da40 audio::ListenerEffectPs2Type::vfunc_3 (6 B): matches/0x0024da40.cpp
// sym: _FUN_0024da40
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// the om::MetaType of an audio listener effect type (records.h)
extern "C" OmMetaType* FUN_0024da40() {
    return &DAT_004e63c8;
}

} // namespace fn_f56426cf

// 0x0024da50 audio::ListenerEffectPs2Type::vfunc_2 (76 B): equivalent/0x0024da50.cpp
// sym: ?vfunc_2@ListenerEffectPs2Type@audio@@UAEPAXXZ @01b08f442d1f @wbb59f4c70fdf
// STATUS: equivalent (tools/equiv.py level 3: 19943 inputs, branch coverage 2/2)
// audio::ListenerEffectPs2Type::vfunc_2 @ 0x0024da50
void* audio::ListenerEffectPs2Type::vfunc_2() {
    Factory* factory = (Factory*)&(*(void**)&DAT_004e6548);
    ListenerEffectPs2_24da50* mem = FUN_00247530(factory);
    if (!mem) return (void*)(0);
    mem->FUN_0025e6f0(factory);
    ListenerEffectPs2_24da50* effect = new (mem) ListenerEffectPs2_24da50;
    ((Returned*)factory->vfunc_3())->FUN_0025fb00(effect);
    return (void*)(effect);
}

