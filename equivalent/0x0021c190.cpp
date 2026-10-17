// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 2/2)
// FUN_0021c190 @ 0x0021c190
struct State {
    int unused;
    int previous;
    int current;
    int result;
    int value;
    int kind;
    int nextValue;
};
int __cdecl FUN_0021bbc0(State *, int *);
// equiv-conv: FUN_0021c190 esi
void FUN_0021c190(State *state)
{
    state->current = state->previous;
    if (state->kind != 0x11f) {
        state->result = state->kind;
        state->value = state->nextValue;
        state->kind = 0x11f;
    } else {
        state->result = FUN_0021bbc0(state, &state->value);
    }
}
