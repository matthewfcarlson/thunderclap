#include "gen/owners.h"
struct Obj {
};
extern Obj gObj;
int atexit(void (*)(void));
extern "C" void FUN_00363c50();

void Reg() {
    ((owners::String_23fc40 *)&gObj)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00363c50);
}
