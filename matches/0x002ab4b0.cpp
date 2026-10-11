extern "C" void _ReadWriteBarrier();
extern int vt1, vt2;
class Ref {
  public:
    virtual void f0();
    virtual void Release();
};
class D {
  public:
    void* vptr;
    char p[0x10];
    Ref* a14;
    Ref* a18;
    ~D() throw();
};
D::~D() throw() {
    vptr = &vt1;
    _ReadWriteBarrier();
    if (a14) {
        a14->Release();
        a14 = 0;
    }
    if (a18) {
        a18->Release();
        a18 = 0;
    }
    vptr = &vt2;
}
