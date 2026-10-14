// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 12/12)
// FUN_00220e90 @ 0x00220e90
struct State_220e90 { unsigned kind; unsigned value; };
struct Buffer_220e90 { char pad[12]; unsigned* words; };
struct Context { Buffer_220e90* buffer; };
void __cdecl FUN_00220d90(Context*, State_220e90*);
void __cdecl FUN_00220c40(Context*, unsigned, int);
void __cdecl FUN_00220bd0(Context*, int, unsigned, unsigned, int);
void __cdecl FUN_00220c10(Context*, int, unsigned, unsigned);
// equiv-conv: FUN_00220e90 ebx esi edi
void FUN_00220e90(State_220e90* state, unsigned value, Context* context) {
 FUN_00220d90(context, state);
 switch(state->kind) {
 case 1: FUN_00220c40(context,value,1); break;
 case 2: case 3: FUN_00220bd0(context,2,value,state->kind==2,0); break;
 case 4: FUN_00220c10(context,1,value,state->value); break;
 case 10: { unsigned& word=context->buffer->words[state->value]; word=(word&0x00ffffffu)|(value<<24); break; }
 case 11: if(value!=state->value) FUN_00220bd0(context,0,value,state->value,0); break;
 default: return;
 }
 state->value=value;
 state->kind=11;
}
