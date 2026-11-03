#include "compat/ptr.h"
#include "gen/owners.h"
typedef unsigned int u32_25b730;
struct Helper_25b730 {
};
struct Obj_25b730 {
    u32_25b730 first;
    void Target(void*, u32_25b730);
};
extern "C" void __cdecl FUN_0025b5b0(void *, void *);
extern "C" char __cdecl FUN_0025b320(void *, void *, const void *);
void Obj_25b730::Target(void* a, u32_25b730 b) {
    FUN_0025b5b0((void *)(hulk_uintptr)(unsigned int)first, a);
    ((owners::Text_240190 *)(((Helper_25b730*)((char*)a + 0x10))))->FUN_00240190((const owners::Text_240190 *)(hulk_uintptr)(unsigned int)b);
    FUN_0025b320((void *)(hulk_uintptr)(unsigned int)first, a, (const void *)(hulk_uintptr)(unsigned int)b);
}