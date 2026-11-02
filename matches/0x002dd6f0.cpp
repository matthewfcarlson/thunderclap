#include "compat/ptr.h"
extern "C" void __cdecl FUN_002dd6b0();
typedef unsigned int u32_2dd6f0;
struct Obj_2dd6f0 {
    char pad0[0x4c];
    u32_2dd6f0 field4c;
    hulk_uintptr field50;
    char pad54[8];
    u32_2dd6f0 field5c;
    char pad60[0xe4];
    u32_2dd6f0 field144;
};
extern "C" void * __cdecl FUN_002e69d0(void *, void *);
extern "C" void FUN_002dd6f0(void * p, unsigned int value, void* fn) {
    ((Obj_2dd6f0 *)p)->field5c = value;
    if (fn)
        ((Obj_2dd6f0 *)p)->field50 = (hulk_uintptr)fn;
    else
        ((Obj_2dd6f0 *)p)->field50 = ((hulk_intptr)(void (__cdecl*)())&FUN_002dd6b0);
    if (((Obj_2dd6f0 *)p)->field4c) {
        ((Obj_2dd6f0 *)p)->field4c = 0;
        FUN_002e69d0((Obj_2dd6f0 *)((Obj_2dd6f0 *)p), (void *)(const char *)"It's an error to set both read_data_fn and write_data_fn in the ");
        FUN_002e69d0((Obj_2dd6f0 *)((Obj_2dd6f0 *)p), (void *)(const char *)"same structure.  Resetting write_data_fn to NULL.");
    }
    ((Obj_2dd6f0 *)p)->field144 = 0;
}