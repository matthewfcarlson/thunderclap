// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 4/4)
// FUN_00212f70 @ 0x00212f70
// FUN_00212f70 @ 0x00212f70
#include "compat/ptr.h"
struct Result { int value; };
Result* __fastcall FUN_00212bb0(void* first, void* second);
extern "C" void * __cdecl FUN_00217600(void *, void *);
extern "C" int __cdecl FUN_00212f70(void* first, void* second) {
    char scratch[8];
    Result* result = FUN_00212bb0(second, first);
    if (result->value != 3 && ((int)(hulk_uintptr)FUN_00217600((Result *)result, scratch)) == 0)
        return 0;
    return 1;
}
