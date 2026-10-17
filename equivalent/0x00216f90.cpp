// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 10/10)
// FUN_00216f90 @ 0x00216f90
struct Item {
    char pad0[5];
    unsigned char flags;
    char pad6[0x40-6];
    int count;
    Item *next;
};
struct State {
    char pad0[0x2c];
    int value2c;
    int value30;
    char pad34[4];
    int value38;
    char pad3c[0x54-0x3c];
    int count;
    Item *alternate;
    Item *primary;
};
struct Owner { char pad0[0x10]; State *state; };
void __cdecl FUN_002164b0(State *, Item *);
// equiv-conv: FUN_00216f90 edi
void FUN_00216f90(Owner *owner) {
    State *state = owner->state;
    state->value2c = 0;
    state->value30 = 0;
    Item *item = state->primary;
    if (item->flags & 3) FUN_002164b0(state, item);
    item = state->primary;
    if (item->count >= 4) {
        Item *next = item->next;
        if (next->flags & 3) FUN_002164b0(state, next);
    }
    State *current = owner->state;
    if (current->count >= 4) {
        Item *alternate = current->alternate;
        if (alternate->flags & 3) FUN_002164b0(state, alternate);
    }
    state->value38 = 0;
}