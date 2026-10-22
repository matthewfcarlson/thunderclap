#include "compat/ptr.h"
#include "gen/audio.h"
extern "C" char hulk_at_004e64d8[];
extern "C" int atexit(void (*)(void));
extern void __cdecl FUN_00364300();
struct ListenerEffectGcType_35fae0 {
    void f();
};
void __cdecl FUN_0035fae0() {
    ((ListenerEffectGcType_35fae0*)(((audio::ListenerEffectGcType*)((hulk_intptr)hulk_at_004e64d8))))->f();
    atexit((void (*)(void))FUN_00364300);
}
