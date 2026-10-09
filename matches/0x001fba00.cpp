class A {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(unsigned*);
};
struct S {
    unsigned a, b, c, d, e, f, g;
};
extern S* __stdcall FUN_001c3d90(unsigned*);
class B {
  public:
    void g();
};
void __fastcall FUN_001fba00(A* p) {
    S x;
    p->f8(&x.a);
    x.d = x.a;
    x.e = x.b;
    x.f = x.c;
    x.g = 0x3f800000;
    S* y = FUN_001c3d90(&x.d);
    ((B*)y)->g();
}