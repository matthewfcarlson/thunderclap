typedef unsigned int u32_212e20;
struct Pair_212e20 {
    u32_212e20 a, b;
};
struct Obj_212e20 {
    char pad[8];
    Pair_212e20* end;
};
Pair_212e20* __fastcall FUN_00212bb0(Obj_212e20*, Obj_212e20*);
void FUN_00212e20(Obj_212e20* self, Obj_212e20* x) {
    Pair_212e20* p = FUN_00212bb0(x, self);
    Pair_212e20* q = self->end;
    while (q > p) {
        q->a = (q - 1)->a;
        q->b = (q - 1)->b;
        --q;
    }
    q = self->end;
    p->a = q->a;
    p->b = q->b;
}