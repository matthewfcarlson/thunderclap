#include "compat/ptr.h"
#include "gen/core.h"
extern "C" int __cdecl Allocate(int, int);
struct MemoryDlAllocator_26cf60 {
    int Process(int, hulk_intptr, int, int);
};

int __cdecl FUN_0026cf60(hulk_intptr param_1, int param_2, int param_3) {
    int size = Allocate(0x4a4, 4);
    if (param_1 != 0)
        return ((MemoryDlAllocator_26cf60*)(((core::MemoryDlAllocator*)(param_1))))->Process(1, size + param_1, param_2 - size, param_3);
    return 0;
}