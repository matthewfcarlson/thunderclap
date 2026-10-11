struct Obj {
    virtual void V0();
    virtual void V1();
};
struct Sub {
    Obj* obj;
    void Init(int, int);
    void Set(int);
    void Stop();
    void Start(int);
    void End();
};
struct C3 {
    void f();
};
struct C2 {
    C3* f();
};
struct C1 {
    C2* f();
};
struct C0 {
    C1* f();
};
struct HitReactionAction {
    char p0[0x20];
    C0* m20;
    Sub sub;
    char p28[0x24];
    Obj* m4c;
    int m50;
    char m54;
    void vfunc_5(int b, int a);
};
void HitReactionAction::vfunc_5(int b, int a) {
    if (!b && !m54)
        sub.Init(m50, a);
    Obj* old = m4c;
    m54 = 0;
    if (old != sub.obj) {
        m20->f()->f()->f();
    }
    sub.Set(b);
    if (b == m50 - 1)
        sub.Start(1);
    Obj* q = sub.obj;
    if (q)
        q->V0();
    if (m4c)
        m4c->V1();
    m4c = q;
    sub.End();
}
