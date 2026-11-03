#include "decls/data/game/hulkfight/motion.h"
// data: gDevice = DAT_004e0fb0
#include "gen/owners.h"

extern "C" int __cdecl atexit(void (*f)());
extern "C" void __cdecl FUN_00363f50();
struct Device {
};
void __cdecl FUN_0035e3a0() {
    ((owners::String_23fc40 *)&((*(Device*)&DAT_004e0fb0)))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00363f50);
}
