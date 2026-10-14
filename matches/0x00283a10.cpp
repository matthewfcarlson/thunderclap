struct B_283a10 {
    void F(int);
};
struct C_283a10 {
    void G(int);
};
struct V {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int, int);
};
class A_283a10 {
  public:
    char p[12];
    B_283a10* a;
    char q[4];
    C_283a10* b;
    V* c;
    void Run(int);
};
void A_283a10::Run(int x) {
    a->F(x);
    b->G(x);
    c->f6(x, 0);
}