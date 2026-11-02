#include "compat/ptr.h"
typedef unsigned char u8;
extern "C" void __cdecl FUN_002e7fb0(void *);
extern "C" void __cdecl FUN_002d9170(void *, void *);
struct Obj_2d73f0 {
    char pad[0x64];
    u8 flags;
};
extern "C" void __cdecl FUN_002d73f0(Obj_2d73f0* p, int a) {
    if ((p->flags & 0x40) == 0)
        FUN_002e7fb0(p);
    FUN_002d9170(p, (void *)(hulk_uintptr)(int)a);
}