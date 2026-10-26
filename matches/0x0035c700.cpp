#include "decls/data/game/global.h"

struct Reg {
    void Register(const char* name, int flag);
};
void FnSound();
void __cdecl FUN_00363af0();
extern "C" int __cdecl _atexit(void(__cdecl* f)());
void __cdecl FUN_0035c700() {
    (*(Reg*)&DAT_004dc020).Register("sound/rsd", 0);
    _atexit(FUN_00363af0);
}
