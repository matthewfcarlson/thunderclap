class A_1fba00 {
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
struct S_1fba00 {
    unsigned a, b, c, d, e, f, g;
};
// FUN_001c3d90 is the 0-argument singleton getter; the pushed pointer is the argument of FUN_001c4010.
struct Registry_1fba00 {
    void FUN_001c4010(unsigned*);
};
Registry_1fba00* FUN_001c3d90();
void __fastcall FUN_001fba00(A_1fba00* p) {
    S_1fba00 x;
    p->f8(&x.a);
    x.d = x.a;
    x.e = x.b;
    x.f = x.c;
    x.g = 0x3f800000;
    FUN_001c3d90()->FUN_001c4010(&x.d);
}
