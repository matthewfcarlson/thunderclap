// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 12/12)
// FUN_00217490 @ 0x00217490
struct State { char pad0[0x34]; unsigned int pending; unsigned int status; char pad1[0x0c]; unsigned int cursor; unsigned int base; };
struct Context { char pad[0x10]; State* state; };
// equiv-conv: FUN_00217350 eax stack
void __cdecl FUN_00217350(Context*, int);
// equiv-conv: FUN_00216f90 edi
void __cdecl FUN_00216f90(Context*);
// equiv-conv: FUN_00216ed0 eax
void __cdecl FUN_00216ed0(unsigned int);
void __cdecl FUN_00217490(Context* context) {
 State* state = context->state;
 while (state->status != 3) FUN_00217350(context, 0x7fffffff);
 FUN_00216f90(context);
 while (state->status != 3) FUN_00217350(context, 0x7fffffff);
 state->cursor = state->base + 0x140;
 while (context->state->pending != 0) FUN_00216ed0(context->state->pending);
}
