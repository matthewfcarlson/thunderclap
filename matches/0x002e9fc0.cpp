#include "compat/ptr.h"
typedef unsigned int u32_2e9fc0;
typedef unsigned char u8;
extern void Parse(void*, u8*);
extern "C" void __cdecl FUN_002e69f0(void *, void *);
extern void Continue(void*, u32_2e9fc0);
extern "C" void FUN_002e9fc0(void* self, hulk_uintptr param2, u32_2e9fc0 param3) {
    u8* flag = (u8*)self + 0x114;
    Parse(self, flag);
    if ((*flag & 0x20) == 0 && (FUN_002e69f0(self, (void *)(const char *)"unknown critical chunk"), param2 == 0))
        return;
    u32_2e9fc0* state = (u32_2e9fc0*)((char*)self + 0x60);
    if ((*state & 4) != 0)
        *state |= 8;
    Continue(self, param3);
}