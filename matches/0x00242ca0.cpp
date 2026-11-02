#include "decls/data/engine/unknown.h"
// data: globalBss = DAT_004e5df8

#include "compat/ptr.h"
typedef unsigned int u32_242ca0;
struct Item_242ca0 {
    char pad[0x10];
    int member;
    char pad2[0x0c];
    hulk_intptr at20;
};
extern "C" void __cdecl FUN_002424a0(void *, void *);
extern "C" void FUN_00257f00(void*, void*);
extern void f3(void*, Item_242ca0*);
void target(void* param1, Item_242ca0** param2) {
    Item_242ca0* p = *param2;
    *param2 = 0;
    FUN_002424a0((char*)param1 + 0x14, (Item_242ca0 *)p);
    FUN_00257f00((char*)p->at20 + 0x28, (char*)p + 0x10);
    f3(((char*)&DAT_004e5df8), p);
}