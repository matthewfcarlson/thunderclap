#include "gen/core.h"
typedef unsigned int U_26cf20;
extern U_26cf20 g_26cf20;
extern U_26cf20 __cdecl lookup(U_26cf20, U_26cf20);
struct MemoryDlAllocator_nv_26cf20 {
    U_26cf20 run(U_26cf20, U_26cf20, U_26cf20);
};
U_26cf20 __cdecl target(U_26cf20 a, U_26cf20 b, U_26cf20 c) {
    g_26cf20 = b;
    U_26cf20 x = lookup(b, 0x4a4);
    if (x)
        return ((MemoryDlAllocator_nv_26cf20*)(((core::MemoryDlAllocator*)x)))->run(a, b, c);
    return 0;
}