#include "compat/ptr.h"
typedef unsigned int u32_219d20;
typedef unsigned char u8;
extern void* Copy(void*, void*, u32_219d20, u32_219d20);
struct Data_219d20 {
    char pad0[7];
    u8 count;
    char pad8[4];
    hulk_uintptr ptrC;
    hulk_uintptr ptr10;
    char pad14[8];
    u32_219d20 count1C;
};
void Target(void* a, Data_219d20* b) {
    if (b->count)
        Copy(a, (void*)b->ptr10, (1 << b->count) * 20, 0);
    Copy(a, (void*)b->ptrC, b->count1C << 3, 0);
    Copy(a, b, 32, 0);
}