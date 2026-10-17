// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_00220a50 @ 0x00220a50
struct Data { char pad[12]; unsigned int *words; };
struct Owner { Data *data; };
struct State { unsigned int kind; unsigned int index; };
void __cdecl FUN_00220a50(Owner *owner, State *state, int value)
{
    if (state->kind != 12) return;
    unsigned int &word = owner->data->words[state->index];
    word ^= (((value + 1) << 6) ^ word) & 0x7fc0;
    if (value == 1) {
        state->kind = 11;
        state->index = ((unsigned char *)&owner->data->words[state->index])[3];
    }
}