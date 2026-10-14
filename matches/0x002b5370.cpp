extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2b5370[];
class Ref_2b5370 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class Helper_2b5370 {
  public:
    void Fn();
};
class A_2b5370 {
  public:
    void* vptr;
    char p[0x3c];
    Ref_2b5370* m40;
    Ref_2b5370* m44;
    Ref_2b5370* m48;
    void f();
};
void A_2b5370::f() {
    vptr = g_vftable_2b5370;
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
    ((Helper_2b5370*)this)->Fn();
}
