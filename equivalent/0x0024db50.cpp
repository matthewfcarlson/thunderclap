// STATUS: equivalent (tools/equiv.py level 3: 19943 inputs, branch coverage 2/2)
// audio::ListenerEffectWin32Type::vfunc_2 @ 0x0024db50
#include "decls/data/engine/audio.h"

namespace audio { struct ListenerEffectWin32; struct ListenerEffectWin32Type { virtual void vfunc_0(); virtual void vfunc_1(); virtual ListenerEffectWin32* vfunc_2(); virtual void vfunc_3(); }; struct ListenerEffectWin32 { virtual void vfunc_0(); void FUN_0025e6f0(void*); }; }
struct Factory { virtual void vfunc_0()=0; virtual void vfunc_1()=0; virtual void vfunc_2()=0; virtual void* vfunc_3(audio::ListenerEffectWin32*)=0; };
extern void* DAT_00429598[];
void* __cdecl FUN_00247530(void*);
struct EffectResult { void FUN_0025fb00(audio::ListenerEffectWin32*); };
audio::ListenerEffectWin32* audio::ListenerEffectWin32Type::vfunc_2() {
 audio::ListenerEffectWin32* obj = (audio::ListenerEffectWin32*)FUN_00247530(((char*)&DAT_004e65b8));
 if (!obj) return 0;
 obj->FUN_0025e6f0(((char*)&DAT_004e65b8));
 *(void***)obj = DAT_00429598;
 EffectResult* result = (EffectResult*)((Factory*)&(*(char*)&DAT_004e65b8))->vfunc_3(obj);
 result->FUN_0025fb00(obj);
 return obj;
}