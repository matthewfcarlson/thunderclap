#include "decls/data/game/global.h"
// data: hulk_at_004ddf68 = DAT_004ddf68

#include "compat/ptr.h"
extern "C" void __cdecl FUN_00363e20();
// cl-flags: /O1
extern "C" void _atexit(void (*)(void));
struct Mgr {
    void Reg(const char* name, int a);
};
void __cdecl FUN_0035d700() {
    ((Mgr*)((hulk_intptr)((char*)&DAT_004ddf68)))->Reg("sound/rsd", 0);
    _atexit(FUN_00363e20);
}
