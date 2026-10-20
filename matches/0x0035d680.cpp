#include "compat/ptr.h"
extern "C" char hulk_at_00400488[];
extern "C" __int64 __cdecl FUN_0027b020(hulk_intptr);
extern "C" __int64 result;
void FUN_0035d680() {
    result = FUN_0027b020(((hulk_intptr)hulk_at_00400488));
}