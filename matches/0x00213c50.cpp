struct Obj_213c50 {
    char pad[8];
    int pos;
};
struct Ctx_213c50 {};
extern int __fastcall GetThing(Ctx_213c50*, Obj_213c50*);
extern int __cdecl Check(Obj_213c50*, int, int);
void __cdecl target(Obj_213c50* p, Ctx_213c50* q) {
    int v = GetThing(q, p);
    int r = Check(p, *(int*)(v + 4), p->pos - 8);
    volatile int* z = &p->pos;
    int n = *z;
    if (r)
        *z = n + 8;
    else
        *z = n - 8;
}