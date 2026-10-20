#include "compat/ptr.h"
typedef unsigned int u32_26db70;
extern "C" void* __stdcall ConvertThreadToFiber(void*);
struct Obj_26db70 {
    char pad0[8];
    int(__cdecl* fn)(int);
    int arg;
    char pad10[12];
    hulk_uintptr field1c;
    u32_26db70 field20;
    char pad24[4];
    u32_26db70 field28;
    char pad2c[12];
    unsigned char field38;
    char pad39[3];
    int result;
};
extern "C" int __stdcall FUN_0026db70(Obj_26db70* p) {
    p->field20 = 0;
    p->field1c = (hulk_uintptr)ConvertThreadToFiber(0);
    p->result = p->fn(p->arg);
    p->field38 = 0;
    p->field28 = 0;
    return 0;
}