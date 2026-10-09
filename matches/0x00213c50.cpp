struct Obj { char pad[8]; int pos; }; struct Ctx {};
extern int __fastcall GetThing(Ctx*, Obj*);
extern int __cdecl Check(Obj*, int, int);
void __cdecl target(Obj* p, Ctx* q) {
 int v=GetThing(q,p);
 int r=Check(p,*(int*)(v+4),p->pos-8);
 volatile int* z=&p->pos;
 int n=*z;
 if(r) *z=n+8; else *z=n-8;
}