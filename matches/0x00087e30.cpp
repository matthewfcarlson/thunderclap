typedef unsigned int u32;
extern unsigned __int64 FUN_00267f40();
extern int FUN_001d4c90();
struct Obj;
struct Handler { void Register(const char *, Obj *, void (*)()); };
extern void FUN_000860c0();
struct Obj { u32 v; u32 x; u32 a,b,c,d,e,f; u32 pad[6]; u32 limit; u32 other; };
Obj * __fastcall FUN_00087e30(Obj *p) {
    p->limit = 0x10000; p->other = 0;
    unsigned __int64 q = FUN_00267f40();
    p->a=(u32)q; p->b=(u32)(q>>32);
    p->c=0; p->d=0; p->e=0; p->f=0; p->v=0x1046a; p->x=0;
    Handler *h=(Handler *)FUN_001d4c90();
    if (h) h->Register("time_GetElapsedTime",p,FUN_000860c0);
    return p;
}