// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0024dbe0..0x0024dca0 (kind game, layer engine, confidence medium), dominant class audio::ListenerEffectPspType
#include "tree_prelude.h"
#include "decls/address.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#define TREE_TU_BEGIN namespace fn_f28ff79c {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f28ff79c {} using namespace fn_f28ff79c;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f28ff79c {
struct Id_24dbe0 {
    __int64 value;
    Id_24dbe0(const char* s) : value(FUN_002672f0(s, 0, 0)) {}
};
class FUN_0025e6c0 {
  public:
    virtual void f();
    FUN_0025e6c0(const Id_24dbe0&, const Id_24dbe0&, int, int, int);
};
class ListenerEffectPspType : public FUN_0025e6c0 {
  public:
    virtual void f();
    ListenerEffectPspType();
};
namespace audio {
struct ListenerEffectPsp;
}
struct ConfigResult { void FUN_0025fb00(audio::ListenerEffectPsp*); };
namespace om {
struct Type { virtual void vfunc_0(); virtual void vfunc_1(); virtual void* vfunc_2(); virtual ConfigResult* vfunc_3(); };
}
extern "C" void* __cdecl FUN_00247530(void*);
} // namespace fn_f28ff79c
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f28ff79c {
namespace audio {
struct ListenerEffectPsp { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); void FUN_0025e6f0(void*); };
}
namespace audio {
struct ListenerEffectPspType : om::Type { virtual void* vfunc_2(); virtual ConfigResult* vfunc_3(); };
}


// 0x0024dbe0 FUN_0024dbe0 (92 B): matches/0x0024dbe0.cpp
// sym: ??0ListenerEffectPspType@fn_f28ff79c@@QAE@XZ
ListenerEffectPspType::ListenerEffectPspType()
    : FUN_0025e6c0(Id_24dbe0("Data_Effect"), Id_24dbe0("ListenerEffectPsp"), 0x1000104, 0x38, 8) {}


// 0x0024dc40 audio::ListenerEffectPspType::vfunc_3 (6 B): matches/0x0024dc40.cpp
// sym: _FUN_0024dc40
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// the om::MetaType of an audio listener effect type (records.h)
extern "C" OmMetaType* FUN_0024dc40() {
    return &DAT_004e6430;
}


// 0x0024dc50 audio::ListenerEffectPspType::vfunc_2 (76 B): equivalent/0x0024dc50.cpp
// sym: ?vfunc_2@ListenerEffectPspType@audio@fn_f28ff79c@@UAEPAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 2/2)
// audio::ListenerEffectPspType::vfunc_2 @ 0x0024dc50
namespace audio {
void* ListenerEffectPspType::vfunc_2() {
    ListenerEffectPsp* obj = (ListenerEffectPsp*)FUN_00247530(((char*)&DAT_004e6628));
    if (!obj) return 0;
    obj->FUN_0025e6f0(((char*)&DAT_004e6628));
    new (obj) ListenerEffectPsp;
    om::Type* config = (om::Type*)(void*)&(*(char*)&DAT_004e6628);
    ConfigResult* result = config->vfunc_3();
    result->FUN_0025fb00(obj);
    return obj;
}
}

} // namespace fn_f28ff79c
