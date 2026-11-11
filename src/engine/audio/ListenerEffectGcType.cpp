// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0024d8e0..0x0024d9a0 (kind game, layer engine, confidence medium), dominant class audio::ListenerEffectGcType
#include "tree_prelude.h"
#include "decls/address.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#define TREE_TU_BEGIN namespace fn_f7b972c5 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f7b972c5 {} using namespace fn_f7b972c5;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f7b972c5 {
typedef unsigned __int64 U64;
namespace audio {
class FUN_0025e6c0 {
  public:
    FUN_0025e6c0(const U64*, const U64*, int, int, int);
    virtual ~FUN_0025e6c0();
};
}
namespace audio {
class ListenerEffectGcType : public FUN_0025e6c0 {
  public:
    ListenerEffectGcType();
    virtual ~ListenerEffectGcType();
};
}


// 0x0024d8e0 FUN_0024d8e0 (92 B): matches/0x0024d8e0.cpp
// sym: ??0ListenerEffectGcType@audio@fn_f7b972c5@@QAE@XZ
namespace audio {
ListenerEffectGcType::ListenerEffectGcType()
    : FUN_0025e6c0(&(const U64&)FUN_002672f0("Data_Effect", 0, 0), &(const U64&)FUN_002672f0("ListenerEffectGc", 0, 0),
                           0x1000102, 64, 8) {}
}


// 0x0024d940 audio::ListenerEffectGcType::vfunc_3 (6 B): matches/0x0024d940.cpp
// sym: _FUN_0024d940
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// the om::MetaType of an audio listener effect type (records.h)
extern "C" OmMetaType* FUN_0024d940() {
    return &DAT_004e63fc;
}

} // namespace fn_f7b972c5

// 0x0024d950 audio::ListenerEffectGcType::vfunc_2 (76 B): equivalent/0x0024d950.cpp [wrapped: conflict: audio::ListenerEffectGcType]
// sym: ?vfunc_2@ListenerEffectGcType@audio@fn_0024d950@@UAEPAUListenerEffectGc@23@XZ
inline void* operator new(size_t, void* location) { return location; }
namespace fn_0024d950 {
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 2/2)
// audio::ListenerEffectGcType::vfunc_2 @ 0x0024d950

/* size_t: tree_prelude.h */

namespace audio {
struct ListenerEffectGc {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    void FUN_0025e6f0(void*);
};
struct ListenerEffectGcType {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual ListenerEffectGc* vfunc_2();
    virtual void vfunc_3();
};
}
struct Registry {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void* vfunc_3();
};
extern "C" audio::ListenerEffectGc* __cdecl FUN_00247530(void*);
struct Result { void FUN_0025fb00(audio::ListenerEffectGc*); };
audio::ListenerEffectGc* audio::ListenerEffectGcType::vfunc_2() {
    ListenerEffectGc* effect = FUN_00247530(((Registry*)&DAT_004e64d8));
    if (!effect) return 0;
    effect->FUN_0025e6f0(((Registry*)&DAT_004e64d8));
    new (effect) ListenerEffectGc;
    Registry* registry = ((Registry*)&DAT_004e64d8);
    Result* result = (Result*)registry->vfunc_3();
    result->FUN_0025fb00(effect);
    return effect;
}
} // namespace fn_0024d950

