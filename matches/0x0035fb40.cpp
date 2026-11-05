#include "decls/data/engine/audio.h"

extern "C" void __cdecl FUN_00364330();
extern void __cdecl _atexit(void (*)(void));
class ListenerEffectPspType_35fb40 {
  public:
    void FUN_0024dbe0();
};
void __cdecl FUN_0035fb40() {
    (*(ListenerEffectPspType_35fb40*)&DAT_004e6628).FUN_0024dbe0();
    _atexit(FUN_00364330);
}
