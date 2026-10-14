extern "C" void _ReadWriteBarrier();
extern int vt1_2e04e0;
extern int vt2_2e04e0;
extern int vt3;
class Ref_2e04e0 {
  public:
    virtual void f0();
    virtual void Release();
};
class Root_2e04e0 {
  public:
    void* vptr;
    ~Root_2e04e0() throw();
};
class D : public Root_2e04e0 {
  public:
    char p40[60];
    Ref_2e04e0* a40;
    char p5c[24];
    Ref_2e04e0* a5c;
    Ref_2e04e0* a60;
    Ref_2e04e0* a64;
    ~D() throw();
};
D::~D() throw() {
    vptr = &vt1_2e04e0;
    _ReadWriteBarrier();
    if (a60) {
        a60->Release();
        a60 = 0;
    }
    if (a64) {
        a64->Release();
        a64 = 0;
    }
    vptr = &vt2_2e04e0;
    _ReadWriteBarrier();
    if (a5c) {
        a5c->Release();
        a5c = 0;
    }
    vptr = &vt3;
    _ReadWriteBarrier();
    if (a40) {
        a40->Release();
        a40 = 0;
    }
}
