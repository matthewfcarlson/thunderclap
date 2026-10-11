extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Ref {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class Sub {
  public:
    void Fn();
};
class Helper {
  public:
    void Fn();
};
class A {
  public:
    void* vptr;
    char p[0x18];
    int m1c;
    Ref* m20;
    Sub m24;
    char p28[0x24];
    Ref* m4c;
    void f();
};
void A::f() {
    vptr = g_vftable;
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
    ((Helper*)this)->Fn();
}
