#include "gen/owners.h"
typedef unsigned int u32_1817d0;
struct ThisCall_00035ef0 {
};
extern "C" u32_1817d0 __cdecl FUN_001817d0(void* p, int n) {
    if (p) {
        if (n < 0)
            return *(u32_1817d0*)((char*)p + 0x128);
        if (n < 8)
            return ((unsigned int)((owners::C_35ef0 *)(((ThisCall_00035ef0*)(p))))->FUN_00035ef0((hulk_intptr)n));
    }
    return 0;
}