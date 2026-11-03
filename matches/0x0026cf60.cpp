#include "compat/ptr.h"
#include "gen/core.h"
extern "C" int __cdecl Allocate(int, int);
struct MemoryDlAllocator_nv_26cf60 {
    int Process(int, hulk_intptr, int, int);
};

int __cdecl FUN_0026cf60(hulk_intptr base, int total, int arg) {
    int size = Allocate(0x4a4, 4);
    if (base != 0)
        return ((MemoryDlAllocator_nv_26cf60*)(((core::MemoryDlAllocator*)(((core::MemoryDlAllocator*)(base))))))->Process(1, size + base, total - size, arg);
    return 0;
}