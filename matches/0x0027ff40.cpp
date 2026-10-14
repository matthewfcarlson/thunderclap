class A_27ff40 {
  public:
    void f(int, int);
};
class B_27ff40 {
  public:
    void f(int, int);
};
class V {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void f(int, int);
};
class C_27ff40 {
  public:
    char p[12];
    A_27ff40* a;
    char q[4];
    B_27ff40* b;
    V* c;
    void f(int, int);
};
void C_27ff40::f(int x, int y) {
    a->f(x, y);
    b->f(x, y);
    c->f(x, y);
}