#include "compat/ptr.h"
typedef unsigned int u32_2eaf30;
struct Obj_2eaf30 {
    char pad[0x24];
    void(__cdecl* fn)(u32_2eaf30, u32_2eaf30);
    u32_2eaf30 value;
};
void __cdecl FUN_002ea2a0(Obj_2eaf30*, Obj_2eaf30*, int);
extern "C" int __cdecl FUN_002eaf30(void * a, void * b) {
    FUN_002ea2a0(((Obj_2eaf30 *)a), ((Obj_2eaf30 *)b), 0);
    ((Obj_2eaf30 *)b)->fn(((Obj_2eaf30 *)b)->value, ((Obj_2eaf30 *)a)->value);
    ((Obj_2eaf30 *)b)->fn(((Obj_2eaf30 *)b)->value, *((u32_2eaf30*)((char*)((Obj_2eaf30 *)a) + 0x24)));
    ((Obj_2eaf30 *)b)->fn(((Obj_2eaf30 *)b)->value, (hulk_uintptr)((Obj_2eaf30 *)a));
    return 0;
}