struct Obj { char pad[8]; unsigned* out; }; struct Pair { unsigned a,b; };
Obj* __fastcall FUN_00212bb0(unsigned, Obj*);
Pair* __cdecl FUN_00219dc0(unsigned, unsigned);
void __cdecl FUN_00213640(Obj* a, unsigned b, unsigned c) {
 Obj* p=FUN_00212bb0(b,a);
 Pair* q=FUN_00219dc0(*(unsigned*)((char*)p+4),c);
 unsigned* out=a->out; out[0]=q->a; out[1]=q->b; a->out=(unsigned*)((char*)a->out+8);
}