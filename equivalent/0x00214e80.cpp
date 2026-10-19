// STATUS: equivalent (tools/equiv.py level 3: 2421 inputs, branch coverage 0/0)
// FUN_00214e80 @ 0x00214e80
struct State_214e80;
struct Node { char pad0[5]; unsigned char flags; char pad6[2]; unsigned int a; unsigned int b; };
struct Value_214e80 { unsigned int tag; void* data; };
struct Detail_214e80 { char pad0[0x1c]; Node* node; char pad20[0x28]; unsigned int bytes; unsigned int count; char pad50[4]; Value_214e80 value; };
struct State_214e80 { char pad0[5]; unsigned char flags; char pad6[10]; Detail_214e80* detail; char pad14[0x2c]; Value_214e80 value; };
extern Node* __cdecl FUN_0021add0(State_214e80*,int,int,int);
extern void __cdecl FUN_00217130(State_214e80*,Node*,int);
// equiv-conv: FUN_00214dd0 edi esi
extern void FUN_00214dd0(State_214e80*, State_214e80*);
extern void* __cdecl FUN_00219cc0(State_214e80*,int,int);
extern void __cdecl FUN_002192e0(State_214e80*,int);
extern void __cdecl FUN_00217520(State_214e80*);
extern void __cdecl FUN_0021aeb0(State_214e80*);
extern Node* __cdecl FUN_00219430(State_214e80*,const char*,int);
void __cdecl FUN_00214e80(State_214e80* s) {
 Node* n=FUN_0021add0(s,0,0,16);
 n->b=0; n->a=0;
 s->detail->node=n;
 FUN_00217130(s,n,7);
 n->flags |= 0x20;
 s->flags |= 0x20;
 FUN_00214dd0(s, s);
 void* p=FUN_00219cc0(s,0,4);
 s->value.data=p; s->value.tag=5;
 Value_214e80* v=&s->detail->value;
 p=FUN_00219cc0(s,4,4);
 v->data=p; v->tag=5;
 FUN_002192e0(s,0x2000);
 FUN_00217520(s);
 FUN_0021aeb0(s);
 n=FUN_00219430(s,"not enough memory",17);
 n->flags |= 0x20;
 Detail_214e80* d=s->detail;
 d->bytes=d->count<<2;
}
