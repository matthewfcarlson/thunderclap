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
    char p[0x420];
    Ref* m424;
    Ref* m428;
    char p42c[0x4c];
    Ref* m478;
    void f();
};
void A::f() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m478) {
        m478->f1();
        m478 = 0;
    }
    if (m424) {
        m424->f1();
        m424 = 0;
    }
    if (m428) {
        m428->f1();
        m428 = 0;
    }
    ((Helper*)this)->Fn();
}
