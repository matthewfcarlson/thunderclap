// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 34/34)
// FUN_00088670 @ 0x00088670
struct Sim;
struct Cfg { char pad[0x2c]; int v2c; };
struct Ctx {
    void *FUN_00086320();
    Cfg *FUN_00086380();
};
struct A { A *FUN_000b3c90(int a); void FUN_000b3d00(); };
struct B { B *FUN_0009dd20(); void FUN_00098e20(Ctx *c); };
struct Sys10 { void FUN_001b3fc0(); };
struct C { C *FUN_001e7470(); void FUN_001de360(Sim *s); };
struct D { D *FUN_00106e90(int n); void FUN_001063e0(); };
struct E { E *FUN_001aec00(); void FUN_001acd80(); };
struct F { F *FUN_00025a90(); void FUN_000243f0(Sim *s); };
struct G { G *FUN_002023e0(); void FUN_00203490(); };
struct H { H *FUN_001ff580(); void FUN_00200c10(Sim *s); };
struct I { I *FUN_001cd150(); void FUN_001cfb20(Sim *s); };
struct J { J *FUN_001cc360(); void FUN_001cb3f0(Sim *s); };
struct K { K *FUN_001ebba0(Sim *s, Ctx *c); void FUN_001eebc0(); };
struct L { L *FUN_001f6c30(); void FUN_001f81c0(); };
struct M { M *FUN_000d75c0(); void FUN_000d6f00(int v); };
struct N { N *FUN_001bceb0(); };
struct O { O *FUN_00059ad0(); };
struct P { P *FUN_001fae80(); void FUN_001fb1e0(); };
struct Q { Q *FUN_0007f950(); void FUN_00078c50(Sim *s); };
struct R { void FUN_00066c20(); };

extern void *__cdecl FUN_0008d690(unsigned int n);
Sys10 *__cdecl FUN_001b6580();
void *__cdecl FUN_001b6990();
R *__stdcall FUN_000678d0(Sim *s);

struct Sim {
    void FUN_00088670(Ctx *ctx, int arg1);
    int pad0;
    A *a;     // 4
    B *b;     // 8
    C *c;     // c
    Sys10 *s10; // 10
    void *s14;
    D *d;     // 18
    E *e;     // 1c
    F *f;     // 20
    G *g;     // 24
    H *h;     // 28
    I *i;     // 2c
    J *j;     // 30
    K *k;     // 34
    L *l;     // 38
    M *m;     // 3c
    N *n;     // 40
    O *o;     // 44
    P *p;     // 48
    Q *q;     // 4c
    Cfg *cfg50; // 50
    Ctx *ctx;   // 54
    void *p58;  // 58
    char pad1[0x9d - 0x5c];
    char ready;
};

void Sim::FUN_00088670(Ctx *arg0, int arg1)
{
    ctx = arg0;
    p58 = arg0->FUN_00086320();
    cfg50 = arg0->FUN_00086380();

    A *ta = (A *)FUN_0008d690(0xc);
    if (ta)
        ta = ta->FUN_000b3c90(arg1);
    a = ta;
    ta->FUN_000b3d00();

    B *tb = (B *)FUN_0008d690(0xc8);
    if (tb)
        tb = tb->FUN_0009dd20();
    b = tb;
    tb->FUN_00098e20(arg0);

    s10 = FUN_001b6580();
    s10->FUN_001b3fc0();

    C *tc = (C *)FUN_0008d690(0x1eee8);
    if (tc)
        tc = tc->FUN_001e7470();
    c = tc;
    tc->FUN_001de360(this);

    s14 = FUN_001b6990();

    D *td = (D *)FUN_0008d690(0x10);
    if (td)
        td = td->FUN_00106e90(0x100);
    d = td;
    td->FUN_001063e0();

    E *te = (E *)FUN_0008d690(0x2c);
    if (te)
        te = te->FUN_001aec00();
    e = te;
    te->FUN_001acd80();

    F *tf = (F *)FUN_0008d690(0xd40);
    if (tf)
        tf = tf->FUN_00025a90();
    f = tf;
    tf->FUN_000243f0(this);

    G *tg = (G *)FUN_0008d690(0x68);
    if (tg)
        tg = tg->FUN_002023e0();
    g = tg;
    tg->FUN_00203490();

    H *th = (H *)FUN_0008d690(0x43c);
    if (th)
        th = th->FUN_001ff580();
    h = th;
    th->FUN_00200c10(this);

    I *ti = (I *)FUN_0008d690(0x14ac);
    if (ti)
        ti = ti->FUN_001cd150();
    i = ti;
    ti->FUN_001cfb20(this);

    J *tj = (J *)FUN_0008d690(0x404);
    if (tj)
        tj = tj->FUN_001cc360();
    j = tj;
    tj->FUN_001cb3f0(this);

    K *tk = (K *)FUN_0008d690(8);
    if (tk)
        tk = tk->FUN_001ebba0(this, arg0);
    k = tk;
    tk->FUN_001eebc0();

    L *tl = (L *)FUN_0008d690(0x60);
    if (tl)
        tl = tl->FUN_001f6c30();
    l = tl;
    tl->FUN_001f81c0();

    M *tm = (M *)FUN_0008d690(0x10);
    if (tm)
        tm = tm->FUN_000d75c0();
    m = tm;
    m->FUN_000d6f00(ctx->FUN_00086380()->v2c);

    N *tn = (N *)FUN_0008d690(0x2c);
    if (tn)
        tn = tn->FUN_001bceb0();
    n = tn;

    O *to = (O *)FUN_0008d690(0x10);
    if (to)
        to = to->FUN_00059ad0();
    o = to;

    P *tp = (P *)FUN_0008d690(0x34);
    if (tp)
        tp = tp->FUN_001fae80();
    p = tp;
    tp->FUN_001fb1e0();

    Q *tq = (Q *)FUN_0008d690(0x3838);
    if (tq)
        tq = tq->FUN_0007f950();
    q = tq;
    tq->FUN_00078c50(this);

    FUN_000678d0(this)->FUN_00066c20();
    ready = 1;
}
