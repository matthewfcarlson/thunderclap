// STATUS: equivalent (tools/equiv.py level 3: 3044 inputs, branch coverage 22/22)
// FUN_001a4fd0 @ 0x001a4fd0
struct Entry { char reserved[9]; unsigned char value; char trailing[6]; };
struct State { char reserved[0x50]; Entry entries[20]; };
unsigned char __cdecl FUN_001a4fd0(const State* state, unsigned int index)
{
    if (index > 19) return 1;
    return state->entries[index].value;
}
