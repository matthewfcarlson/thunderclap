#include "compat/ptr.h"
typedef unsigned int uint;
struct Item_213190 {
    int type;
    int value;
};
Item_213190* __fastcall GetItem(int, hulk_intptr);
int __cdecl Check(hulk_intptr, Item_213190*);
void __cdecl Update(hulk_intptr);
int __cdecl FUN_00213190(hulk_intptr a, int b) {
    Item_213190* p = GetItem(b, a);
    if (p->type == 4)
        return p->value + 0x10;
    int result = Check(a, p) ? p->value + 0x10 : 0;
    volatile uint* q = (volatile uint*)(*(hulk_uintptr*)(a + 0x10));
    uint high = q[19];
    if (high >= q[18])
        Update(a);
    return result;
}