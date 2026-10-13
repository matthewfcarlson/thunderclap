// STATUS: equivalent (tools/equiv.py level 3: 3044 inputs, branch coverage 22/22)
// FUN_001a5110 @ 0x001a5110
struct Entry { unsigned char value; char padding[15]; };
struct State { char padding[0x58]; Entry entries[20]; };
unsigned char __cdecl FUN_001a5110(const State* state, unsigned int index)
{
    if (index >= 20) return 1;
    return state->entries[index].value;
}
