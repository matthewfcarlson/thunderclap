// STATUS: equivalent (tools/equiv.py level 3: 2390 inputs, branch coverage 4/4)
// FUN_00334c40 @ 0x00334c40
struct State {
    char unused[0x20];
    void *pending;
    char rest[0x5c];
    unsigned char processing;
};
void thunk_FUN_00270a50();
// equiv-conv: FUN_00334c40 esi
void FUN_00334c40(State *state) {
    state->processing = 1;
    while (state->pending != 0) {
        thunk_FUN_00270a50();
    }
    state->processing = 0;
}
