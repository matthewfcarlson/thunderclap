#include "decls/data/game/global.h"
// data: items = DAT_004ddb68 (two rows of six 8-byte objects built by 0x000b06e0)

struct Obj_b06e0 {
    char bytes[8];
};
extern "C" void __stdcall FUN_00011520(void*, int, int, void(__cdecl*)(Obj_b06e0*));
extern "C" void __cdecl FUN_000b06e0(Obj_b06e0*);
void __cdecl FUN_00363dc0();
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl FUN_0035d2d0() {
    Obj_b06e0* p = (Obj_b06e0*)DAT_004ddb68;
    int n = 2;
    do {
        FUN_00011520(p, 8, 6, FUN_000b06e0);
        p += 6;
    } while (--n);
    atexit(FUN_00363dc0);
}
