#include "decls/data/engine/unknown.h"

typedef unsigned int u32_263df0;
struct Item_263df0 {
    char pad[0x10];
    u32_263df0 value;
};
extern "C" void * __cdecl FUN_00263970(void *, const void *);
u32_263df0 FUN_00263df0(u32_263df0 a, u32_263df0 b) {
    u32_263df0 key[2];
    key[0] = a;
    key[1] = b;
    Item_263df0* p = ((Item_263df0 *)FUN_00263970(((u32_263df0**)&DAT_004cd4cc), (unsigned int *)key));
    if (p)
        return p->value;
    return 0;
}