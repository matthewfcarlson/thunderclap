#include "compat/ptr.h"
struct Obj_242f60 {
    char pad0[0x28];
    int field28;
    char pad2c[8];
    int field34;
};
extern "C" void __cdecl FUN_00242da0(void *, void *);
extern "C" void FUN_00242f60(int a, Obj_242f60* b, int c) {
    if (b->field34 == 0)
        FUN_00242da0((void *)(hulk_uintptr)(int)a, (Obj_242f60 *)b);
    if (b->field34 != 2) {
        b->field34 = 1;
        b->field28 = c;
    }
}