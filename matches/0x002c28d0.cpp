extern "C" void _ReadWriteBarrier();
extern int vt1_2c28d0;
class Ref_2c28d0 {
  public:
    virtual void f0();
    virtual void Release();
};
class Root_2c28d0 {
  public:
    void* vptr;
    ~Root_2c28d0() throw();
};
class D : public Root_2c28d0 {
  public:
    char p58[84];
    Ref_2c28d0* a58;
    Ref_2c28d0* a5c;
    Ref_2c28d0* a60;
    Ref_2c28d0* a64;
    ~D() throw();
};
D::~D() throw() {
    vptr = &vt1_2c28d0;
    _ReadWriteBarrier();
    if (a58) {
        a58->Release();
        a58 = 0;
    }
    if (a5c) {
        a5c->Release();
        a5c = 0;
    }
    if (a60) {
        a60->Release();
        a60 = 0;
    }
    if (a64) {
        a64->Release();
        a64 = 0;
    }
}
