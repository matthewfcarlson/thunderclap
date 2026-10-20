#include "compat/ptr.h"
extern "C" char hulk_at_0040048c[];
extern "C" unsigned long long __cdecl __fastload(hulk_intptr);
extern unsigned long long g_35d440;
void FUN_0035d440() {
    g_35d440 = __fastload(((hulk_intptr)hulk_at_0040048c));
}
