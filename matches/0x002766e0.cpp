extern "C" char DAT_003f6098[];
extern "C" char DAT_0042bdd0[];
extern "C" char DAT_0042bddc[];
struct V {
    virtual void A();
    virtual void B();
};
struct Obj {
    void** v;
    void** v4;
    int pad;
    V* p;
    void f();
};
void Obj::f() {
    v = (void**)((int)DAT_0042bddc);
    v4 = (void**)((int)DAT_0042bdd0);
    p->B();
    v = (void**)((int)DAT_003f6098);
}