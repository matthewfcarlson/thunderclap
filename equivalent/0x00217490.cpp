// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 12/12)
// FUN_00217490 @ 0x00217490
struct State_217490 { char pad0[0x34]; unsigned int pending; unsigned int status; char pad1[0x0c]; unsigned int cursor; unsigned int base; };
struct Context { char pad[0x10]; State_217490* state; };
// equiv-conv: FUN_00217350 eax stack
void __cdecl FUN_00217350(Context*, int);
// equiv-conv: FUN_00216f90 edi
void __cdecl FUN_00216f90(Context*);
// equiv-conv: FUN_00216ed0 esi
void __cdecl FUN_00216ed0(Context*);
void __cdecl FUN_00217490(Context* context) {
 State_217490* state = context->state;
 while (state->status != 3) FUN_00217350(context, 0x7fffffff);
 FUN_00216f90(context);
 while (state->status != 3) FUN_00217350(context, 0x7fffffff);
 state->cursor = state->base + 0x140;
 while (context->state->pending != 0) FUN_00216ed0(context);
}
