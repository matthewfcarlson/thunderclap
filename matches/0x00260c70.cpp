#include "decls/data/engine/om.h"

extern "C" char DAT_0042aad0[];
typedef unsigned int u32_260c70;
extern void __stdcall Init(void*, void*, int, int);
extern "C" void* __fastcall FUN_00260c70(void* p, void* edx) {
    Init((void*)((int)DAT_004e58d0), (void*)((int)DAT_004e58c8), 0x24, 4);
    *(u32_260c70*)p = ((int)DAT_0042aad0);
    return p;
}