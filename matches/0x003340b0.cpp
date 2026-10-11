extern "C" char DAT_003f6098[];
extern "C" char DAT_0042af64[];
extern "C" char DAT_004342bc[];
extern "C" char DAT_004342c4[];
struct V {
    virtual void f();
    virtual void g();
};
struct X {
    void** v;
    int a;
    int b;
    char p0[4];
    V* p;
    char pad[0x20];
    V* q;
};
extern int global;
void __fastcall FUN_003340b0(X* x) {
    x->v = (void**)((int)DAT_004342c4);
    x->a = (int)((int)DAT_004342bc);
    if (x->p) {
        x->p->g();
        x->p = 0;
    }
    if (x->q) {
        x->q->g();
        x->q = 0;
    }
    global = x->b;
    x->a = (int)((int)DAT_0042af64);
    x->v = (void**)((int)DAT_003f6098);
}