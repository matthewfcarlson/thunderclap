#include "gen/owners.h"
extern "C" void __cdecl FUN_00363f30();
extern void __cdecl _atexit(void (*func)());
struct Obj {
    void FUN_0023fc40(const char*, float);
};
extern Obj gObj;
void FUN_0035e340() {
    ((owners::String_23fc40 *)&gObj)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    _atexit(FUN_00363f30);
}
