#include "compat/ptr.h"
typedef unsigned int u32_2e6e00;
struct Obj_2e6e00 {
    char pad0[0x1c];
    hulk_intptr field1c;
    char pad20[4];
    int(__cdecl* callback)(int, int);
    int field28;
};
extern "C" int __cdecl FUN_002eaf30(void *, void *);
extern "C" int __cdecl FUN_002e6e00(void * p) {
    if (((Obj_2e6e00 *)p) && ((Obj_2e6e00 *)p)->field1c && ((Obj_2e6e00 *)p)->callback) {
        int v = *(int*)(((Obj_2e6e00 *)p)->field1c + 0x14);
        if (v)
            FUN_002eaf30((void *)(hulk_uintptr)(int)v, (Obj_2e6e00 *)((Obj_2e6e00 *)p));
        ((Obj_2e6e00 *)p)->callback(((Obj_2e6e00 *)p)->field28, ((Obj_2e6e00 *)p)->field1c);
        ((Obj_2e6e00 *)p)->field1c = 0;
        return 0;
    }
    return -2;
}