// STATUS: equivalent (tools/equiv.py level 3: 14531 inputs, branch coverage 2/2)
// FUN_0021cd30 @ 0x0021cd30
// FUN_0021cd30 @ 0x0021cd30
#include "compat/ptr.h"
struct State { int unknown; int value4; int value8; int valueC; int value10; int value14; int value18; int value1C; };
extern "C" int __cdecl FUN_0021bbc0(void *, void *);
extern "C" int __cdecl FUN_0021ded0(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002211e0(void *, void *);
// equiv-conv: FUN_0021c2e0 esi eax
extern "C" void __cdecl FUN_0021c2e0(void *, int);
// equiv-conv: FUN_0021cd30 eax edi
void FUN_0021cd30(State *state, hulk_intptr edi) {
    state->value8 = state->value4;
    if (state->value14 == 0x11f) {
        state->valueC = FUN_0021bbc0((State *)state, (int *)(&state->value10));
    } else {
        state->valueC = state->value14;
        state->value10 = state->value18;
        state->value14 = 0x11f;
    }
    FUN_0021ded0((State *)state, (void *)(hulk_uintptr)(int)edi, 0);
    FUN_002211e0((void *)(hulk_uintptr)(int)(state->value1C), (void *)(hulk_uintptr)(int)edi);
    FUN_0021c2e0((State *)state, 0x5d);
}
