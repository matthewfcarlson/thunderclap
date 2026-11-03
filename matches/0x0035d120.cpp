#include "decls/data/game/global.h"
#include "gen/owners.h"

extern "C" void __cdecl FUN_00363cd0();
extern "C" int __cdecl atexit(void (*f)());
struct Reg {
};
void InitSound() {
    ((owners::String_23fc40 *)&((*(Reg*)&DAT_004dd818)))->FUN_0023fc40((const char *)(((char*)&DAT_003f3ea0)), (hulk_intptr)0);
    atexit(FUN_00363cd0);
}
