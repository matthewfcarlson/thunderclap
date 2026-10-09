class pddiViewState {
  public:
    virtual void vfunc_0(void*);
    int a, b, c, d, e, f, g, h, i, j, k, l;
};
class View {
  public:
    virtual void x0();
    virtual void x1();
    virtual void x2();
    virtual void x3();
    virtual void x4();
    virtual void x5();
    virtual void A(int);
    virtual void x7();
    virtual void B(int);
    virtual void x9();
    virtual void C(int);
    virtual void x11();
    virtual void x12();
    virtual void x13();
    virtual void x14();
    virtual void x15();
    virtual void x16();
    virtual void x17();
    virtual void x18();
    virtual void x19();
    virtual void x20();
    virtual void x21();
    virtual void x22();
    virtual void x23();
    virtual void D(int);
    virtual void xx();
    virtual void E(int, int, int, int);
    virtual void xxx();
    virtual void F(int, int, int, int);
};
void pddiViewState::vfunc_0(void* p) {
    View* v = (View*)p;
    v->A(a);
    v->B(b);
    v->C(c);
    v->D(d);
    v->E(e, f, g, h);
    v->F(i, j, k, l);
}