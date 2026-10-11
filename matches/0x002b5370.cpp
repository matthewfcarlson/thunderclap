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
    char p[0x3c];
    Ref* m40;
    Ref* m44;
    Ref* m48;
    void f();
};
void A::f() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m40) {
        m40->f1();
        m40 = 0;
    }
    if (m44) {
        m44->f1();
        m44 = 0;
    }
    if (m48) {
        m48->f1();
        m48 = 0;
    }
    ((Helper*)this)->Fn();
}
