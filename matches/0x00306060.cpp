#include "compat/ptr.h"
typedef int u32_306060;
extern "C" bool __cdecl Check1(u32_306060, hulk_intptr, u32_306060);
extern "C" char __cdecl Check2(u32_306060, u32_306060, u32_306060);
bool __cdecl Target(u32_306060 a, u32_306060 b, u32_306060 c) {
    char r = Check1(a, b, c);
    if (r == 0)
        return false;
    return Check2(a, b, c);
}
