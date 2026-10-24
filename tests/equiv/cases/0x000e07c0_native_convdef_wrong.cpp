// STATUS: equivalent (tools/equiv.py level 3: 2958 inputs, branch coverage 0/0)
// FUN_000e07c0 @ 0x000e07c0
struct Triple_e07c0 { unsigned x,y,z; };
struct State_e07c0 { char pad[8]; Triple_e07c0* position; unsigned reserved; unsigned* value; };
// equiv-conv: FUN_0008ef00 ecx
void __cdecl FUN_0008ef00(State_e07c0*, ...);
// equiv-conv: FUN_000e07c0 esi stack stack stack stack stack stack stack
void __cdecl FUN_000e07c0(State_e07c0* state, unsigned x1, unsigned y1, unsigned z1, unsigned x2, unsigned y2, unsigned z2, unsigned value) {
 Triple_e07c0* p=state->position;
 p->x=x1; p->z=z1; p->y=y1;
 *state->value=value;
 FUN_0008ef00(state);
 p=state->position;
 p->x=x2; p->z=z2; p->y=y2;
 *state->value=value;
 FUN_0008ef00(state,x1,y1,z1,x1,y1,z1,value);
 volatile unsigned barrier=0;
}
