typedef unsigned int U_293d40;
struct Obj_293d40 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17(int, void*);
};
struct Holder_293d40 {
    Obj_293d40* p;
};
struct Sub_293d40 {
    void init();
};
extern U_293d40 g0_293d40, g1, g2, g4, g5, g6;
extern Sub_293d40 gS;
struct C_293d40 {
    Holder_293d40 h;
    void run(U_293d40, U_293d40, U_293d40);
};
void C_293d40::run(U_293d40 a, U_293d40 b, U_293d40 c) {
    g0_293d40 = a;
    g1 = b;
    g2 = c;
    gS.init();
    g4 = g0_293d40;
    g5 = g1;
    g6 = g2;
    h.p->f17(0, (void*)&gS);
}
