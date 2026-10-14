extern "C" void _ReadWriteBarrier();
extern void* g_vftable_aa0d0[];
class Ref_aa0d0 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class Helper_aa0d0 {
  public:
    void Fn();
};
class A_aa0d0 {
  public:
    void* vptr;
    char p[0x420];
    Ref_aa0d0* m424;
    Ref_aa0d0* m428;
    char p42c[0x4c];
    Ref_aa0d0* m478;
    void f();
};
void A_aa0d0::f() {
    vptr = g_vftable_aa0d0;
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
    ((Helper_aa0d0*)this)->Fn();
}
