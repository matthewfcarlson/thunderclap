extern "C" void _ReadWriteBarrier();
extern int vt1_2e02a0;
extern int vt2_2e02a0;
class Ref_2e02a0 {
  public:
    virtual void f0();
    virtual void Release();
};
class Root_2e02a0 {
  public:
    void* vptr;
    ~Root_2e02a0() throw();
};
class D : public Root_2e02a0 {
  public:
    char p40[60];
    Ref_2e02a0* a40;
    char p5c[24];
    Ref_2e02a0* a5c;
    ~D() throw();
};
D::~D() throw() {
    vptr = &vt1_2e02a0;
    _ReadWriteBarrier();
    if (a5c) {
        a5c->Release();
        a5c = 0;
    }
    vptr = &vt2_2e02a0;
    _ReadWriteBarrier();
    if (a40) {
        a40->Release();
        a40 = 0;
    }
}
