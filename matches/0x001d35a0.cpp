#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" unsigned int __cdecl strlen(const char*);
void __cdecl Init(int, int);
int owners::Obj_1d35a0::FUN_001d35a0(const char* text, hulk_intptr x, hulk_intptr len) {
    Init(handle, 0);
    if (len == -1)
        len = strlen(text);
    int result = 3;
    if (Do(handle, text, len, ((int)x)))
        result = 0;
    state = result;
    return result;
}