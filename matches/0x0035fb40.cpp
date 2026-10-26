#include "decls/data/engine/audio.h"

extern void __cdecl FUN_00364330();
extern void __cdecl _atexit(void (*)(void));
class ListenerEffectPspType_35fb40 {
  public:
    void Run();
};
void __cdecl FUN_0035fb40() {
    (*(ListenerEffectPspType_35fb40*)&DAT_004e6628).Run();
    _atexit(FUN_00364330);
}
