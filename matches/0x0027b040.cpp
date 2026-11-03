#include "gen/owners.h"
typedef unsigned int U32_27b040;
typedef unsigned __int64 U64_27b040;
U64_27b040 __cdecl MakeThing(U32_27b040, U32_27b040, U32_27b040);
U64_27b040 owners::Target_27b040::FUN_0027b040(hulk_uintptr value) {
    U64_27b040 result;
    if (((U32_27b040)value))
        result = MakeThing(((U32_27b040)value), 0, 0);
    else
        result = 0;
    a = (U32_27b040)result;
    b = (U32_27b040)(result >> 32);
    return result;
}