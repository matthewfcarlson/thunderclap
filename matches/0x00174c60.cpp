extern "C" void _ReadWriteBarrier();
extern void* g_vftable_174c60[];
class Ref_174c60 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class Helper_174c60 {
  public:
    void Fn();
};
class A_174c60 {
  public:
    void* vptr;
    char p[0x18];
    int m1c;
    Ref_174c60* m20;
    char p24[4];
    Ref_174c60* m28;
    void f();
};
void A_174c60::f() {
    vptr = g_vftable_174c60;
    _ReadWriteBarrier();
    if (m28) {
        m28->f1();
        m28 = 0;
    }
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((Helper_174c60*)this)->Fn();
}
