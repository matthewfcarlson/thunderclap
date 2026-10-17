// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0024c120 @ 0x0024c120
struct State { char pad0[8]; int resource; char pad1[0xb4]; int status; int repeat; }; void __cdecl FUN_00259be0(int);
// equiv-conv: FUN_0024bc70 eax
void FUN_0024bc70(State* state);
void __cdecl FUN_0024c120(State* state) { FUN_00259be0(state->resource); state->status = 2; do { FUN_0024bc70(state); } while (state->repeat == 3); }