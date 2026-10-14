// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 20/20)
// FUN_00217e20 @ 0x00217e20
struct Value { unsigned int type; union { unsigned int bits; float number; struct Object* object; } data; };
struct Object { char pad[8]; void* metatable; };
struct State { char pad[8]; Value* top; };
// equiv-conv: FUN_00217b60 edi ebx esi stack
extern Value* __cdecl FUN_00217b60(void*,void*,int,State*);
// equiv-conv: FUN_00217750 ecx eax edx stack
extern void __cdecl FUN_00217750(State*,Value*,Value*,Value*);
// equiv-conv: FUN_00217790 ecx eax
extern void __cdecl FUN_00217790(State*,Value*);
int __cdecl FUN_00217e20(State* state, Value* left, Value* right) {
 switch(left->type) {
 case 0: return 1;
 case 3: return left->data.number == right->data.number;
 case 5: case 7: {
 if(left->data.object == right->data.object) return 1;
 Value* tm = FUN_00217b60(left->data.object->metatable,right->data.object->metatable,4,state);
 if(!tm) return 0;
 FUN_00217750(state,left,right,tm);
 FUN_00217790(state,state->top);
 Value* result=state->top;
 return result->type != 0 && (result->type != 1 || result->data.bits != 0);
 }
 default: return left->data.bits == right->data.bits;
 }
}