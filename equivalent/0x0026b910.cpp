// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0026b910 @ 0x0026b910
struct Link { Link* next; Link* previous; };
struct State {
    unsigned int flags;
    char reserved0[0x28];
    Link* first;
    char reserved1[4];
    Link links[128];
    char reserved2[0x10];
    unsigned int capacity;
    unsigned int used;
    unsigned int available;
    char reserved3[4];
    unsigned int extra;
    char reserved4[4];
    unsigned int size;
};
// equiv-conv: FUN_0026b910 eax
void FUN_0026b910(State* state) {
    for (int i = 0; i < 127; ++i) {
        state->links[i+1].next = &state->links[i];
        state->links[i+1].previous = &state->links[i];
    }
    state->used = 0;
    state->extra = 0;
    state->available = 0x20000;
    state->capacity = 0x20000;
    state->flags = (state->flags & 2) | 9;
    state->first = &state->links[0];
    state->size = 0x1000;
}