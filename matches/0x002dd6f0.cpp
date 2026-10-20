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
extern void Report(Obj_2dd6f0*, const char*);
void Target(Obj_2dd6f0* p, u32_2dd6f0 value, void* fn) {
    p->field5c = value;
    if (fn)
        p->field50 = (hulk_uintptr)fn;
    else
        p->field50 = ((hulk_intptr)(void (__cdecl*)())&FUN_002dd6b0);
    if (p->field4c) {
        p->field4c = 0;
        Report(p, "It's an error to set both read_data_fn and write_data_fn in the ");
        Report(p, "same structure.  Resetting write_data_fn to NULL.");
    }
    p->field144 = 0;
}