#include "gen/owners.h"
extern "C" void __cdecl FUN_00363c60();
extern "C" int __cdecl atexit(void (*f)());
extern "C" void __cdecl FUN_0023fc40(const char*, int);

struct G {
} g;

void __cdecl FUN_0035cea0() {
    ((owners::String_23fc40 *)&g)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit((void (*)())FUN_00363c60);
}
