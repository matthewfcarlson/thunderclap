// STATUS: equivalent (tools/equiv.py level 3: 3043 inputs, branch coverage 13/14, incomplete)
// FUN_0021f350 @ 0x0021f350
struct Table { char pad[12]; unsigned* flags; }; struct Context { Table* table; char pad[48]; unsigned char state; }; struct Parser { unsigned zero; unsigned current; unsigned previous; unsigned token; unsigned value; unsigned pendingToken; unsigned pendingValue; Context* context; }; struct Item { unsigned type; unsigned index; unsigned rest[3]; };
extern int __cdecl FUN_0021bbc0(Parser*, unsigned*);
// equiv-conv: FUN_0021d5c0 esi edi
extern int FUN_0021d5c0(Parser*, Item*);
extern void __cdecl FUN_00220a50(Context*, Item*, int);
extern unsigned __cdecl FUN_00221190(Context*, Item*);
extern void __cdecl FUN_00221110(Context*, Item*);
extern unsigned __cdecl FUN_00220bd0(Context*, int, unsigned, int, int);
// equiv-conv: FUN_0021f350 eax
unsigned FUN_0021f350(Parser* p) { Context* c=p->context; p->previous=p->current; if(p->pendingToken!=0x11f) { p->token=p->pendingToken; p->value=p->pendingValue; p->pendingToken=0x11f; } else p->token=FUN_0021bbc0(p,&p->value); int result; unsigned value; if(p->token==0x3b) { result=0; value=0; } else { Item item; result=FUN_0021d5c0(p,&item); if(item.type==12) { FUN_00220a50(c,&item,-1); if(result==1) c->table->flags[item.index]=(c->table->flags[item.index]&0xffffffda)|0x1a; value=c->state; result=-1; } else if(result==1) value=FUN_00221190(c,&item); else { FUN_00221110(c,&item); value=c->state; } } return FUN_00220bd0(c,27,value,result+1,0); }