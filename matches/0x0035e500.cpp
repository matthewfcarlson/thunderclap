#include "decls/data/game/hulkfight/motion.h"
// data: hulk_at_004e159c = DAT_004e159c

#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void __cdecl FUN_00363f90();
extern "C" int __cdecl _atexit(void (*)(void));
struct Reg {
};
void FUN_0035e500() {
    ((owners::String_23fc40 *)(((Reg*)((hulk_intptr)((char*)&DAT_004e159c)))))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    _atexit(FUN_00363f90);
}
