// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 34/34)
// FUN_00088670 @ 0x00088670
struct Sim_88670;
struct Cfg_88670 { char pad[0x2c]; int v2c; };
struct Ctx_88670 {
    void *FUN_00086320();
    Cfg_88670 *FUN_00086380();
};
struct A_88670 { A_88670 *FUN_000b3c90(int a); void FUN_000b3d00(); };
struct B_88670 { B_88670 *FUN_0009dd20(); void FUN_00098e20(Ctx_88670 *c); };
struct Sys10 { void FUN_001b3fc0(); };
struct C_88670 { C_88670 *FUN_001e7470(); void FUN_001de360(Sim_88670 *s); };
struct D { D *FUN_00106e90(int n); void FUN_001063e0(); };
struct E_88670 { E_88670 *FUN_001aec00(); void FUN_001acd80(); };
struct F_88670 { F_88670 *FUN_00025a90(); void FUN_000243f0(Sim_88670 *s); };
struct G_88670 { G_88670 *FUN_002023e0(); void FUN_00203490(); };
struct H { H *FUN_001ff580(); void FUN_00200c10(Sim_88670 *s); };
struct I_88670 { I_88670 *FUN_001cd150(); void FUN_001cfb20(Sim_88670 *s); };
struct J_88670 { J_88670 *FUN_001cc360(); void FUN_001cb3f0(Sim_88670 *s); };
struct K_88670 { K_88670 *FUN_001ebba0(Sim_88670 *s, Ctx_88670 *c); void FUN_001eebc0(); };
struct L_88670 { L_88670 *FUN_001f6c30(); void FUN_001f81c0(); };
struct M_88670 { M_88670 *FUN_000d75c0(); void FUN_000d6f00(int v); };
struct N_88670 { N_88670 *FUN_001bceb0(); };
struct O_88670 { O_88670 *FUN_00059ad0(); };
struct P_88670 { P_88670 *FUN_001fae80(); void FUN_001fb1e0(); };
struct Q_88670 { Q_88670 *FUN_0007f950(); void FUN_00078c50(Sim_88670 *s); };
struct R_88670 { void FUN_00066c20(); };

extern void *__cdecl FUN_0008d690(unsigned int n);
Sys10 *__cdecl FUN_001b6580();
void *__cdecl FUN_001b6990();
R_88670 *__stdcall FUN_000678d0(Sim_88670 *s);

struct Sim_88670 {
    void FUN_00088670(Ctx_88670 *ctx, int arg1);
    int pad0;
    A_88670 *a;     // 4
    B_88670 *b;     // 8
    C_88670 *c;     // c
    Sys10 *s10; // 10
    void *s14;
    D *d;     // 18
    E_88670 *e;     // 1c
    F_88670 *f;     // 20
    G_88670 *g;     // 24
    H *h;     // 28
    I_88670 *i;     // 2c
    J_88670 *j;     // 30
    K_88670 *k;     // 34
    L_88670 *l;     // 38
    M_88670 *m;     // 3c
    N_88670 *n;     // 40
    O_88670 *o;     // 44
    P_88670 *p;     // 48
    Q_88670 *q;     // 4c
    Cfg_88670 *cfg50; // 50
    Ctx_88670 *ctx;   // 54
    void *p58;  // 58
    char pad1[0x9d - 0x5c];
    char ready;
};

void Sim_88670::FUN_00088670(Ctx_88670 *arg0, int arg1)
{
    ctx = arg0;
    p58 = arg0->FUN_00086320();
    cfg50 = arg0->FUN_00086380();

    A_88670 *ta = (A_88670 *)FUN_0008d690(0xc);
    if (ta)
        ta = ta->FUN_000b3c90(arg1);
    a = ta;
    ta->FUN_000b3d00();

    B_88670 *tb = (B_88670 *)FUN_0008d690(0xc8);
    if (tb)
        tb = tb->FUN_0009dd20();
    b = tb;
    tb->FUN_00098e20(arg0);

    s10 = FUN_001b6580();
    s10->FUN_001b3fc0();

    C_88670 *tc = (C_88670 *)FUN_0008d690(0x1eee8);
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

    E_88670 *te = (E_88670 *)FUN_0008d690(0x2c);
    if (te)
        te = te->FUN_001aec00();
    e = te;
    te->FUN_001acd80();

    F_88670 *tf = (F_88670 *)FUN_0008d690(0xd40);
    if (tf)
        tf = tf->FUN_00025a90();
    f = tf;
    tf->FUN_000243f0(this);

    G_88670 *tg = (G_88670 *)FUN_0008d690(0x68);
    if (tg)
        tg = tg->FUN_002023e0();
    g = tg;
    tg->FUN_00203490();

    H *th = (H *)FUN_0008d690(0x43c);
    if (th)
        th = th->FUN_001ff580();
    h = th;
    th->FUN_00200c10(this);

    I_88670 *ti = (I_88670 *)FUN_0008d690(0x14ac);
    if (ti)
        ti = ti->FUN_001cd150();
    i = ti;
    ti->FUN_001cfb20(this);

    J_88670 *tj = (J_88670 *)FUN_0008d690(0x404);
    if (tj)
        tj = tj->FUN_001cc360();
    j = tj;
    tj->FUN_001cb3f0(this);

    K_88670 *tk = (K_88670 *)FUN_0008d690(8);
    if (tk)
        tk = tk->FUN_001ebba0(this, arg0);
    k = tk;
    tk->FUN_001eebc0();

    L_88670 *tl = (L_88670 *)FUN_0008d690(0x60);
    if (tl)
        tl = tl->FUN_001f6c30();
    l = tl;
    tl->FUN_001f81c0();

    M_88670 *tm = (M_88670 *)FUN_0008d690(0x10);
    if (tm)
        tm = tm->FUN_000d75c0();
    m = tm;
    m->FUN_000d6f00(ctx->FUN_00086380()->v2c);

    N_88670 *tn = (N_88670 *)FUN_0008d690(0x2c);
    if (tn)
        tn = tn->FUN_001bceb0();
    n = tn;

    O_88670 *to = (O_88670 *)FUN_0008d690(0x10);
    if (to)
        to = to->FUN_00059ad0();
    o = to;

    P_88670 *tp = (P_88670 *)FUN_0008d690(0x34);
    if (tp)
        tp = tp->FUN_001fae80();
    p = tp;
    tp->FUN_001fb1e0();

    Q_88670 *tq = (Q_88670 *)FUN_0008d690(0x3838);
    if (tq)
        tq = tq->FUN_0007f950();
    q = tq;
    tq->FUN_00078c50(this);

    FUN_000678d0(this)->FUN_00066c20();
    ready = 1;
}
