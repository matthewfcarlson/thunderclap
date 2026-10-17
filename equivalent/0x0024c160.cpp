// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0024c160 @ 0x0024c160
struct State { char pad0[8]; int item; char pad1[0xb4]; int mode; int status; };
int __cdecl FUN_00259c50(int);
void __cdecl FUN_00258e50(int);
// equiv-conv: FUN_0024bc70 eax
void __cdecl FUN_0024bc70(State* state);
void __cdecl FUN_0024c160(State* state) {
    if (FUN_00259c50(state->item) == 1) FUN_00258e50(state->item);
    state->mode = 3;
    do {
        FUN_0024bc70(state);
    } while (state->status == 3);
}