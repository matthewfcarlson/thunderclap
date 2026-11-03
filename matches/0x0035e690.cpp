#include "decls/data/game/global.h"
// data: g_mgr = DAT_004e21f8, k_path = DAT_003f3ea0
#include "gen/owners.h"

extern "C" int __cdecl _atexit(void (*)(void));
struct Mgr {
};
extern "C" void __cdecl FUN_00364000(void);
void __cdecl FUN_0035e690() {
    ((owners::String_23fc40 *)&((*(Mgr*)&DAT_004e21f8)))->FUN_0023fc40(DAT_003f3ea0, (hulk_intptr)0);
    _atexit(FUN_00364000);
}
