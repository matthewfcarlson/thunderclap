extern "C" void _ReadWriteBarrier();
extern int vt1_297590;
class Ref_297590 {
  public:
    virtual void f0();
    virtual void Release();
};
class Root_297590 {
  public:
    void* vptr;
    ~Root_297590() throw();
};
class D : public Root_297590 {
  public:
    char p2c[40];
    Ref_297590* a2c;
    ~D() throw();
};
D::~D() throw() {
    vptr = &vt1_297590;
    _ReadWriteBarrier();
    if (a2c) {
        a2c->Release();
        a2c = 0;
    }
}
