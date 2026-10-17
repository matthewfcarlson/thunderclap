// STATUS: equivalent (tools/equiv.py level 3: 2580 inputs, branch coverage 6/6)
// FUN_00217440 @ 0x00217440
struct BufferState {
    char padding0[0x34];
    int flag;
    int mode;
    char padding1[0x0c];
    int start;
    int end;
};
struct Owner {
    char padding[0x10];
    BufferState* state;
};
// equiv-conv: FUN_00217350 eax stack
int FUN_00217350(Owner* owner, int amount);
void FUN_00217440(Owner* owner) {
    BufferState* state = owner->state;
    int result = (state->end - state->start) * 8 + 0xa00;
    do {
        result = FUN_00217350(owner, result);
        if (state->mode == 3 && state->flag == 0)
            break;
    } while (result > 0);
    state->start = state->end - (result / 8) + 0x140;
}