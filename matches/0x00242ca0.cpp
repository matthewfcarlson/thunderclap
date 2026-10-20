#include "compat/ptr.h"
typedef unsigned int u32_242ca0;
struct Item_242ca0 {
    char pad[0x10];
    int member;
    char pad2[0x0c];
    hulk_intptr at20;
};
extern void f1(void*, Item_242ca0*);
extern void f2(void*, void*);
extern void f3(void*, Item_242ca0*);
char globalBss[4];
void target(void* param1, Item_242ca0** param2) {
    Item_242ca0* p = *param2;
    *param2 = 0;
    f1((char*)param1 + 0x14, p);
    f2((char*)p->at20 + 0x28, (char*)p + 0x10);
    f3(globalBss, p);
}