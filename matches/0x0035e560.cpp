#include "decls/data/game/global.h"

extern "C" void __cdecl FUN_00363fc0();
extern "C" int __cdecl atexit(void (*)());

struct Reg {
    void RegFunc(const char* name, int v);
};


void Target() {
    (*(Reg*)&DAT_004e1818).RegFunc("sound/rsd", 0);
    atexit(FUN_00363fc0);
}
