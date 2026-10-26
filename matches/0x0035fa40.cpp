#include "decls/data/engine/audio.h"
// data: gRegistry = DAT_004e6394

typedef void (*AtExitFn)();
void __cdecl _atexit(AtExitFn);
struct Registry {
    void Reg(const char* name, int flags);
};
extern void __cdecl Cleanup();
void __cdecl RegisterEffect() {
    (*(Registry*)&DAT_004e6394).Reg("ListenerEffectWin32", 0);
    _atexit((AtExitFn)Cleanup);
}
