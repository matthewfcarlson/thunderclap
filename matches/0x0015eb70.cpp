extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Ref {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class Helper {
  public:
    void Fn();
};
class A {
  public:
    void* vptr;
    char p[0x18];
    Ref* m1c;
    Ref* m20;
    Ref* m24;
    void f();
};
void A::f() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m24) {
        m24->f1();
        m24 = 0;
    }
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c) {
        m1c->f1();
        m1c = 0;
    }
    ((Helper*)this)->Fn();
}
