struct Obj_151860 {
    virtual void V0();
    virtual void V1();
};
struct Sub_151860 {
    Obj_151860* obj;
    void Init(int, int);
    void Set(int);
    void Stop();
    void Start(int);
    int End();
};
struct C3_151860 {
    void f();
};
struct C2_151860 {
    C3_151860* f();
};
struct C1_151860 {
    C2_151860* f();
};
struct C0_151860 {
    C1_151860* f();
};
struct HitReactionAction {
    char p0[0x20];
    C0_151860* m20;
    Sub_151860 sub;
    char p28[0x24];
    Obj_151860* m4c;
    int m50;
    char m54;
    int vfunc_5(int b, int a);
};
int HitReactionAction::vfunc_5(int b, int a) {
    if (!b && !m54)
        sub.Init(m50, a);
    Obj_151860* old = m4c;
    m54 = 0;
    if (old != sub.obj) {
        m20->f()->f()->f();
    }
    sub.Set(b);
    if (b == m50 - 1)
        sub.Start(1);
    Obj_151860* q = sub.obj;
    if (q)
        q->V0();
    if (m4c)
        m4c->V1();
    m4c = q;
    return sub.End();
}
