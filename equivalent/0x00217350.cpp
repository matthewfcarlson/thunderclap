// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 14/14)
// FUN_00217350 @ 0x00217350
struct Node { int value; }; struct State { char pad0[8]; int limit; char padC[12]; Node fallback; int pad1C; Node* cursor; int count; int active; char pad2C[8]; int pending; unsigned mode; }; struct Object { char pad[16]; State* state; };
// equiv-conv: FUN_00216ac0 eax stack
int __cdecl FUN_00216ac0(int amount, State* state);
// equiv-conv: FUN_00217050 eax
void __cdecl FUN_00217050(Object* object);
int __cdecl FUN_00216e10(int flag, int amount);
Node* __cdecl FUN_002171c0(Object*, Node*, int, int*, int);
// equiv-conv: FUN_00216e70 eax
void __cdecl FUN_00216e70(Node* cursor);
// equiv-conv: FUN_00216ed0 esi
void __cdecl FUN_00216ed0(Object* object);
// equiv-conv: FUN_00216f90 edi
void __cdecl FUN_00216f90(Object* object);
// equiv-conv: FUN_00217350 eax stack
int __cdecl FUN_00217350(Object* object, int amount) { State* s=object->state; switch(s->mode) { case 0: if(s->active) return FUN_00216ac0(amount,s); FUN_00217050(object); return 0; case 1: { int result=FUN_00216e10(1,amount); if(s->count>=s->limit) {s->count=0; s->mode=2;} return result; } case 2: { Node* p=FUN_002171c0(object,s->cursor,1,&amount,0); s->cursor=p; if(!p->value) { FUN_00216e70(p); s->cursor=&s->fallback; s->mode=3; } return amount; } case 3: if(s->pending) {FUN_00216ed0(object); return amount-80;} FUN_00216f90(object); return 0; default: return amount; } }