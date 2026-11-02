#include "compat/ptr.h"
typedef unsigned int U_261980;
extern char* GetText(U_261980);
extern "C" U_261980 FUN_00260b60(U_261980);
extern "C" hulk_uintptr __cdecl FUN_00261980(U_261980 param) {
    char* p = GetText(param);
    if (*p == 't') {
        hulk_uintptr result = (hulk_uintptr)GetText(param);
        FUN_00260b60(param);
        return result;
    }
    FUN_00260b60(param);
    return (hulk_uintptr)GetText(param);
}