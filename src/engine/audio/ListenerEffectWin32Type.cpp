// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0024dae0..0x0024dba0 (kind game, layer engine, confidence medium), dominant class audio::ListenerEffectWin32Type
#include "tree_prelude.h"
#include "decls/address.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#define TREE_TU_BEGIN namespace fn_fa5e70fd {
#define TREE_TU_END }
namespace fn_fa5e70fd {} using namespace fn_fa5e70fd;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_fa5e70fd {
typedef unsigned __int64 U64_24dae0;
class FUN_0025e6c0 {
  public:
    virtual void f();
    FUN_0025e6c0(const U64_24dae0*, const U64_24dae0*, int, int, int);
};
class ListenerEffectWin32Type : public FUN_0025e6c0 {
  public:
    virtual void g();
    ListenerEffectWin32Type();
};
} // namespace fn_fa5e70fd
namespace audio {
struct ListenerEffectWin32_24db50;
}
namespace audio {
struct ListenerEffectWin32_24db50 { virtual void vfunc_0(); void FUN_0025e6f0(void*); };
}
namespace fn_fa5e70fd {
struct Factory { virtual void vfunc_0()=0; virtual void vfunc_1()=0; virtual void vfunc_2()=0; virtual void* vfunc_3()=0; };
extern void* DAT_00429598[];
extern "C" void* __cdecl FUN_00247530(void*);
struct EffectResult { void FUN_0025fb00(audio::ListenerEffectWin32_24db50*); };


// 0x0024dae0 FUN_0024dae0 (92 B): matches/0x0024dae0.cpp
// sym: ??0ListenerEffectWin32Type@fn_fa5e70fd@@QAE@XZ
ListenerEffectWin32Type::ListenerEffectWin32Type()
    : FUN_0025e6c0(&(const U64_24dae0&)FUN_002672f0("Data_Effect", 0, 0), &(const U64_24dae0&)FUN_002672f0("ListenerEffectWin32", 0, 0), 0x1000103, 0x30, 8) {}


// 0x0024db40 audio::ListenerEffectWin32Type::vfunc_3 (6 B): matches/0x0024db40.cpp
// sym: _FUN_0024db40
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// the om::MetaType of an audio listener effect type (records.h)
extern "C" OmMetaType* FUN_0024db40() {
    return &DAT_004e6394;
}

} // namespace fn_fa5e70fd

// 0x0024db50 audio::ListenerEffectWin32Type::vfunc_2 (76 B): equivalent/0x0024db50.cpp
// sym: ?vfunc_2@ListenerEffectWin32Type@audio@@UAEPAXXZ @d1a5f2b86cb8 @w60cb8a79a565
// STATUS: equivalent (tools/equiv.py level 3: 19943 inputs, branch coverage 2/2)
// audio::ListenerEffectWin32Type::vfunc_2 @ 0x0024db50
void* audio::ListenerEffectWin32Type::vfunc_2() {
 audio::ListenerEffectWin32_24db50* obj = (audio::ListenerEffectWin32_24db50*)FUN_00247530(((char*)&DAT_004e65b8));
 if (!obj) return (void*)(0);
 obj->FUN_0025e6f0(((char*)&DAT_004e65b8));
 *(void***)obj = DAT_00429598;
 ((EffectResult*)((Factory*)&(*(char*)&DAT_004e65b8))->vfunc_3())->FUN_0025fb00(obj);
 return (void*)(obj);
}

