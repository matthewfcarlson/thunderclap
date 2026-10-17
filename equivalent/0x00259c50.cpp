// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00259c50 @ 0x00259c50
struct State { char pad[8]; void* value; }; 
// equiv-conv: FUN_00258f40 eax
unsigned char FUN_00258f40(State* state);
void* __cdecl FUN_00259c50(State* state) {
    if (state->value && !FUN_00258f40(state)) state->value = 0;
    return state->value;
}