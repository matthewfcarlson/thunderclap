extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2a9de0[];
class Ref_2a9de0 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class Helper_2a9de0 {
  public:
    void Fn();
};
class A_2a9de0 {
  public:
    void* vptr;
    char p[0x3c];
    Ref_2a9de0* m40;
    Ref_2a9de0* m44;
    char p48[4];
    void* m4c;
    void f();
};
void operator delete[](void*);
void A_2a9de0::f() {
    vptr = g_vftable_2a9de0;
    _ReadWriteBarrier();
    if (m40) {
        m40->f1();
        m40 = 0;
    }
    if (m44) {
        m44->f1();
        m44 = 0;
    }
    operator delete[](m4c);
    ((Helper_2a9de0*)this)->Fn();
}
