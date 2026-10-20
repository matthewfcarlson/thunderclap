#include "compat/ptr.h"
#include "decls/data/engine/core.h"

extern "C" char DAT_003f6098[];
extern "C" char DAT_0042af64[];
extern "C" char DAT_0042b364[];
extern "C" char DAT_0042b36c[];
typedef unsigned int u32_26cc00;
struct MemoryDlAllocator {
    volatile u32_26cc00 vptr;
    volatile u32_26cc00 vptr2;
    volatile u32_26cc00 member;
    void Init();
};
void MemoryDlAllocator::Init() {
    vptr = ((hulk_intptr)DAT_0042b36c);
    vptr2 = ((hulk_intptr)DAT_0042b364);
    *(volatile u32_26cc00*)((hulk_intptr)((char*)&DAT_004cdbb0)) = member;
    vptr2 = ((hulk_intptr)DAT_0042af64);
    vptr = ((hulk_intptr)DAT_003f6098);
}