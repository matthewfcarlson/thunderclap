extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1488a0[];
class Ref_1488a0 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class Sub_1488a0 {
  public:
    void Fn();
};
class Helper_1488a0 {
  public:
    void Fn();
};
class A_1488a0 {
  public:
    void* vptr;
    char p[0x18];
    int m1c;
    Ref_1488a0* m20;
    Sub_1488a0 m24;
    char p28[0x24];
    Ref_1488a0* m4c;
    void f();
};
void A_1488a0::f() {
    vptr = g_vftable_1488a0;
    _ReadWriteBarrier();
    if (m4c) {
        m4c->f1();
        m4c = 0;
    }
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    m24.Fn();
    ((Helper_1488a0*)this)->Fn();
}
