#include "decls/data/engine/audio.h"
#include "decls/data/records.h"
// data: gRegistry = DAT_004e6394

typedef void (*AtExitFn)();
void __cdecl _atexit(AtExitFn);
struct Registry {
    void FUN_0025fa00(const char* name, int flags);
};
extern void __cdecl FUN_003642c0();
void __cdecl RegisterEffect() {
    (*(Registry*)&DAT_004e6394).FUN_0025fa00("ListenerEffectWin32", 0);
    _atexit((AtExitFn)FUN_003642c0);
}
