// STATUS: equivalent (tools/equiv.py level 3: 2972 inputs, branch coverage 6/6)
// FUN_00215910 @ 0x00215910
struct Descriptor { char padding[6]; char flag; };
struct Node { void *head; char padding[8]; int count; };
struct State { char padding0[0x14]; Node *node; char padding1[4]; int position; };
extern void __cdecl FUN_00215520(State *, int, int);
// equiv-conv: FUN_00215910 eax esi
int FUN_00215910(int position, State *state)
{
    int delta = position - state->position;
    FUN_00215520(state, 1, -1);
    Descriptor *descriptor = ((Descriptor **)state->node->head)[-1];
    if (!descriptor->flag) {
        while (state->node->count != 0) {
            --state->node->count;
            FUN_00215520(state, 4, -1);
        }
        --state->node->count;
    }
    return state->position + delta;
}