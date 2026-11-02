// STATUS: equivalent (tools/equiv.py level 3: 3035 inputs, branch coverage 22/22)
// FUN_00217e20 @ 0x00217e20
// FUN_00217e20 @ 0x00217e20
struct Value_217e20 { unsigned int type; union { unsigned int bits; float number; struct Object* object; } data; };
struct Object { char pad[8]; void* metatable; };
struct State_217e20 { char pad[8]; Value_217e20* top; };
// equiv-conv: FUN_00217b60 edi esi ebx stack
extern "C" void * __cdecl FUN_00217b60(void *, int, void *, void *);
// equiv-conv: FUN_00217750 ecx stack eax edx
extern "C" void __cdecl FUN_00217750(void *, const void *, const void *, const void *);
// equiv-conv: FUN_00217790 ecx eax
extern void __cdecl FUN_00217790(State_217e20*,Value_217e20*);
extern "C" int __cdecl FUN_00217e20(void * state, void * left, void * right) {
 switch(((Value_217e20 *)left)->type) {
 case 0: return 1;
 case 3: return ((Value_217e20 *)left)->data.number == ((Value_217e20 *)right)->data.number;
 case 5: case 7: {
 if(((Value_217e20 *)left)->data.object == ((Value_217e20 *)right)->data.object) return 1;
 Value_217e20* tm = ((Value_217e20 *)FUN_00217b60(((Value_217e20 *)left)->data.object->metatable, 4, ((Value_217e20 *)right)->data.object->metatable, (State_217e20 *)((State_217e20 *)state)));
 if(!tm) return 0;
 FUN_00217750((State_217e20 *)((State_217e20 *)state), (Value_217e20 *)tm, (Value_217e20 *)((Value_217e20 *)left), (Value_217e20 *)((Value_217e20 *)right));
 FUN_00217790(((State_217e20 *)state),((State_217e20 *)state)->top);
 Value_217e20* result=((State_217e20 *)state)->top;
 return result->type != 0 && (result->type != 1 || result->data.bits != 0);
 }
 default: return ((Value_217e20 *)left)->data.bits == ((Value_217e20 *)right)->data.bits;
 }
}
