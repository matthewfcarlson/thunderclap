// STATUS: equivalent (tools/equiv.py level 3: 3043 inputs, branch coverage 13/14, incomplete)
// FUN_0021f350 @ 0x0021f350
struct Table_21f350 { char pad[12]; unsigned* flags; }; struct Context { Table_21f350* table; char pad[48]; unsigned char state; }; struct Parser_21f350 { unsigned zero; unsigned current; unsigned previous; unsigned token; unsigned value; unsigned pendingToken; unsigned pendingValue; Context* context; }; struct Item_21f350 { unsigned type; unsigned index; unsigned rest[3]; };
extern "C" int __cdecl FUN_0021bbc0(void *, void *);
// equiv-conv: FUN_0021d5c0 esi edi
extern "C" int __cdecl FUN_0021d5c0(void *, void *);
extern "C" void __cdecl FUN_00220a50(void *, void *, int);
extern "C" int __cdecl FUN_00221190(void *, void *);
extern "C" void __cdecl FUN_00221110(void *, void *);
extern "C" int __cdecl FUN_00220bd0(void *, unsigned int, int, unsigned int, unsigned int);
// equiv-conv: FUN_0021f350 eax
extern "C" unsigned FUN_0021f350(void * p_) {
    Parser_21f350 * p = (Parser_21f350 *)p_; Context* c=p->context; p->previous=p->current; if(p->pendingToken!=0x11f) { p->token=p->pendingToken; p->value=p->pendingValue; p->pendingToken=0x11f; } else p->token=FUN_0021bbc0((Parser_21f350 *)p,(unsigned *)(&p->value)); int result; unsigned value; if(p->token==0x3b) { result=0; value=0; } else { Item_21f350 item; result=FUN_0021d5c0((Parser_21f350 *)p,(Item_21f350 *)(&item)); if(item.type==12) { FUN_00220a50((Context *)c,(Item_21f350 *)(&item),-1); if(result==1) c->table->flags[item.index]=(c->table->flags[item.index]&0xffffffda)|0x1a; value=c->state; result=-1; } else if(result==1) value=((unsigned)FUN_00221190((Context *)c,(Item_21f350 *)(&item))); else { FUN_00221110((Context *)c,(Item_21f350 *)(&item)); value=c->state; } } return ((unsigned)FUN_00220bd0((Context *)c,27,(unsigned)value,(int)(result+1),0)); }