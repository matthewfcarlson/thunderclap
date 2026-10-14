// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 8/8)
// FUN_002149b0 @ 0x002149b0
struct Value_2149b0 { unsigned int type; unsigned int data; };
struct State_2149b0 { char pad0[8]; Value_2149b0* top; char padc[12]; char* limit; char* base; char pad20[36]; void* table; char pad48[12]; unsigned int offset; };
extern void __cdecl FUN_002152b0(State_2149b0*, int);
extern void* __cdecl FUN_00219430(State_2149b0*, const char*, int);
extern Value_2149b0* __cdecl FUN_00219e50(void*, void*);
extern void __cdecl FUN_00215460(State_2149b0*, int);
extern void __cdecl FUN_002159e0(State_2149b0*, Value_2149b0*, int);
void __cdecl FUN_002149b0(State_2149b0* s) {
 Value_2149b0* source;
 if(s->offset) source = (Value_2149b0*)(s->base+s->offset);
 else { void* key=FUN_00219430(s,"_TRACEBACK",10); source=FUN_00219e50(s->table,key); }
 if(source->type!=6) FUN_002152b0(s,5);
 Value_2149b0* top=s->top;
 top->type=top[-1].type;
 top->data=top[-1].data;
 top=s->top-1;
 top->type=source->type;
 top->data=source->data;
 if((int)(s->limit-(char*)s->top)<=8) FUN_00215460(s,1);
 s->top++;
 FUN_002159e0(s,s->top-2,1);
 FUN_002152b0(s,1);
}