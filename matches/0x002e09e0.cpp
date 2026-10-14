extern "C" void _ReadWriteBarrier();
extern int vt1_2e09e0;
extern int vt2_2e09e0;
class Ref_2e09e0 {
  public:
    virtual void f0();
    virtual void Release();
};
class Root_2e09e0 {
  public:
    void* vptr;
    ~Root_2e09e0() throw();
};
class D : public Root_2e09e0 {
  public:
    char p40[60];
    Ref_2e09e0* a40;
    char p58[20];
    Ref_2e09e0* a58;
    Ref_2e09e0* a5c;
    ~D() throw();
};
D::~D() throw() {
    vptr = &vt1_2e09e0;
    _ReadWriteBarrier();
    if (a40) {
        a40->Release();
        a40 = 0;
    }
    if (a58) {
        a58->Release();
        a58 = 0;
    }
    if (a5c) {
        a5c->Release();
        a5c = 0;
    }
    vptr = &vt2_2e09e0;
    _ReadWriteBarrier();
    if (a40) {
        a40->Release();
        a40 = 0;
    }
}
