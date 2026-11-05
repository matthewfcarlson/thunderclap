#include "decls/data/game/global.h"
// data: items = DAT_004ddab0 (two rows of six 8-byte objects built by 0x000b06e0); cleanup = 0x00363d90 (an atexit handler: its invented name stays, see docs/native-build.md "Start-up stops 67 to 216")

struct Obj_b06e0 {
    char bytes[8];
};
extern "C" void __stdcall FUN_00011520(void*, int, int, void(__cdecl*)(Obj_b06e0*));
extern "C" void __cdecl FUN_000b06e0(Obj_b06e0*);
extern "C" void cleanup();
extern "C" int __cdecl atexit(void(__cdecl*)());
void FUN_0035d340() {
    Obj_b06e0* p = (Obj_b06e0*)DAT_004ddab0;
    int n = 2;
    do {
        FUN_00011520(p, 8, 6, FUN_000b06e0);
        p += 6;
    } while (--n);
    atexit(cleanup);
}
