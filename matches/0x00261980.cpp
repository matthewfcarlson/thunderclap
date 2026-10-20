#include "compat/ptr.h"
typedef unsigned int U_261980;
extern char* GetText(U_261980);
extern U_261980 Operate(U_261980);
U_261980 __cdecl Target(U_261980 param) {
    char* p = GetText(param);
    if (*p == 't') {
        hulk_uintptr result = (hulk_uintptr)GetText(param);
        Operate(param);
        return result;
    }
    Operate(param);
    return (hulk_uintptr)GetText(param);
}