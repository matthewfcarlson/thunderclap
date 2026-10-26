#include "decls/data/engine/audio.h"

extern "C" void __cdecl FUN_00254760();
extern "C" void __cdecl FUN_00364590();
extern "C" int atexit(void(__cdecl*)(void));
struct G_360bb0 {
    void f();
};
extern "C" void __cdecl FUN_00360bb0() {
    (*(G_360bb0*)&DAT_004e72f8).f();
    atexit(FUN_00364590);
}
