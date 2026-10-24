// STATUS: equivalent (tools/equiv.py level 3: 2966 inputs, branch coverage 0/0; Wine build 600 inputs, 0/0)
// FUN_000e07c0 @ 0x000e07c0
struct Triple_e07c0 { unsigned x,y,z; };
struct State_e07c0 { char pad[8]; Triple_e07c0* position; unsigned reserved; unsigned* value; };
// FUN_0008ef00 is Stream::FUN_0008ef00 (thiscall, no stack arguments). The original passes the state in ecx: `mov ecx,
// esi; call`, then `mov ecx, esi; jmp` (the tail jump leaves this function's frame words on the stack). MSVC mode is
// proven with the register note and the frame words spelled out; the Wine build (clang) calls the member, so the
// state really goes in ecx (wine_conv_check check 9 listed this call).
#if defined(__clang__)
struct Stream_e07c0 { void FUN_0008ef00(); };
#else
// equiv-conv: FUN_0008ef00 ecx
void __cdecl FUN_0008ef00(State_e07c0*, ...);
#endif
// equiv-conv: FUN_000e07c0 esi stack stack stack stack stack stack stack
void __cdecl FUN_000e07c0(State_e07c0* state, unsigned x1, unsigned y1, unsigned z1, unsigned x2, unsigned y2, unsigned z2, unsigned value) {
 Triple_e07c0* p=state->position;
 p->x=x1; p->z=z1; p->y=y1;
 *state->value=value;
 #if defined(__clang__)
 ((Stream_e07c0*)state)->FUN_0008ef00();
 #else
 FUN_0008ef00(state);
 #endif
 p=state->position;
 p->x=x2; p->z=z2; p->y=y2;
 *state->value=value;
 #if defined(__clang__)
 ((Stream_e07c0*)state)->FUN_0008ef00();
 #else
 FUN_0008ef00(state,x1,y1,z1,x1,y1,z1,value);
 #endif
 volatile unsigned barrier=0;
}
