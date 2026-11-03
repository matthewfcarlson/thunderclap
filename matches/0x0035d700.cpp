#include "decls/data/game/global.h"
// data: hulk_at_004ddf68 = DAT_004ddf68

#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void __cdecl FUN_00363e20();
// cl-flags: /O1
extern "C" void _atexit(void (*)(void));
struct Mgr {
};
void __cdecl FUN_0035d700() {
    ((owners::String_23fc40 *)(((Mgr*)((hulk_intptr)((char*)&DAT_004ddf68)))))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    _atexit(FUN_00363e20);
}
