// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0024c160 @ 0x0024c160
#include "compat/ptr.h"
struct State { char pad0[8]; int item; char pad1[0xb4]; int mode; int status; };
extern "C" void * __cdecl FUN_00259c50(void *);
void __cdecl FUN_00258e50(int);
// equiv-conv: FUN_0024bc70 eax
extern "C" void __cdecl FUN_0024bc70(void *);
extern "C" void __cdecl FUN_0024c160(State* state) {
    if (((int)(hulk_uintptr)FUN_00259c50((void *)(hulk_uintptr)(int)(state->item))) == 1) FUN_00258e50(state->item);
    state->mode = 3;
    do {
        FUN_0024bc70((State *)state);
    } while (state->status == 3);
}