#include "decls/data/engine/audio.h"
// data: hulk_at_004e64d8 = DAT_004e64d8

#include "compat/ptr.h"
#include "gen/audio.h"
extern "C" int atexit(void (*)(void));
extern void __cdecl FUN_00364300();
struct ListenerEffectGcType_nv_35fae0 {
    void f();
};
void __cdecl FUN_0035fae0() {
    ((ListenerEffectGcType_nv_35fae0*)(((audio::ListenerEffectGcType*)(((audio::ListenerEffectGcType*)((hulk_intptr)((char*)&DAT_004e64d8)))))))->f();
    atexit((void (*)(void))FUN_00364300);
}
