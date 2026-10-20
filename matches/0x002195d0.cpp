#include "compat/ptr.h"
extern "C" void* __cdecl FUN_0021add0(void*, int, hulk_intptr, hulk_intptr);
extern "C" void __cdecl FUN_00217130(void*, void*, int);

struct Obj_2195d0 {
    char pad[8];
    int* ptr;
    int value;
};

extern "C" Obj_2195d0* __cdecl FUN_002195d0(void* param) {
    Obj_2195d0* p = (Obj_2195d0*)FUN_0021add0(param, 0, 0, 0x14);
    FUN_00217130(param, p, 10);
    p->ptr = &p->value;
    p->value = 0;
    return p;
}