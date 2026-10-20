#include "compat/ptr.h"
extern "C" char hulk_at_0040048c[];
extern "C" __int64 __cdecl FUN_0027b020(hulk_intptr);
extern "C" __int64 result;
void FUN_0035de80() {
    result = FUN_0027b020(((hulk_intptr)hulk_at_0040048c));
}