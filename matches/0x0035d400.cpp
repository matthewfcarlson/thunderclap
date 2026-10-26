#include "decls/data/game/global.h"

extern "C" void __cdecl FUN_00363df0();
extern "C" int __cdecl _atexit(void(__cdecl*)(void));
struct Reg {
    void Fn(const char*, int);
};
void __cdecl FUN_0035d400() {
    (*(Reg*)&DAT_004ddbe4).Fn("sound/rsd", 0);
    _atexit(FUN_00363df0);
}
