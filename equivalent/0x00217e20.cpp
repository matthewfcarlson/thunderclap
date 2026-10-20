// STATUS: equivalent (tools/equiv.py level 3: 3035 inputs, branch coverage 22/22)
// FUN_00217e20 @ 0x00217e20
// FUN_00217e20 @ 0x00217e20
struct Value_217e20 { unsigned int type; union { unsigned int bits; float number; struct Object* object; } data; };
struct Object { char pad[8]; void* metatable; };
struct State_217e20 { char pad[8]; Value_217e20* top; };
// equiv-conv: FUN_00217b60 edi esi ebx stack
extern Value_217e20* __cdecl FUN_00217b60(void*, int, void*, State_217e20*);
// equiv-conv: FUN_00217750 ecx stack eax edx
extern void __cdecl FUN_00217750(State_217e20*, Value_217e20*, Value_217e20*, Value_217e20*);
// equiv-conv: FUN_00217790 ecx eax
extern void __cdecl FUN_00217790(State_217e20*,Value_217e20*);
int __cdecl FUN_00217e20(State_217e20* state, Value_217e20* left, Value_217e20* right) {
 switch(left->type) {
 case 0: return 1;
 case 3: return left->data.number == right->data.number;
 case 5: case 7: {
 if(left->data.object == right->data.object) return 1;
 Value_217e20* tm = FUN_00217b60(left->data.object->metatable, 4, right->data.object->metatable, state);
 if(!tm) return 0;
 FUN_00217750(state, tm, left, right);
 FUN_00217790(state,state->top);
 Value_217e20* result=state->top;
 return result->type != 0 && (result->type != 1 || result->data.bits != 0);
 }
 default: return left->data.bits == right->data.bits;
 }
}
