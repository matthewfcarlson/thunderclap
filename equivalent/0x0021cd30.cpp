// STATUS: equivalent (tools/equiv.py level 3: 14531 inputs, branch coverage 2/2)
// FUN_0021cd30 @ 0x0021cd30
// FUN_0021cd30 @ 0x0021cd30
struct State { int unknown; int value4; int value8; int valueC; int value10; int value14; int value18; int value1C; };
int __cdecl FUN_0021bbc0(State *, int *);
void __cdecl FUN_0021ded0(State *, int, int);
void __cdecl FUN_002211e0(int, int);
// equiv-conv: FUN_0021c2e0 esi eax
void FUN_0021c2e0(State *, int);
// equiv-conv: FUN_0021cd30 eax edi
void FUN_0021cd30(State *state, int edi) {
    state->value8 = state->value4;
    if (state->value14 == 0x11f) {
        state->valueC = FUN_0021bbc0(state, &state->value10);
    } else {
        state->valueC = state->value14;
        state->value10 = state->value18;
        state->value14 = 0x11f;
    }
    FUN_0021ded0(state, edi, 0);
    FUN_002211e0(state->value1C, edi);
    FUN_0021c2e0(state, 0x5d);
}
