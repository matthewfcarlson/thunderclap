extern "C" void _ReadWriteBarrier();
extern int vt1;
extern int vt2;
extern int vt3;
class Ref {
  public:
    virtual void f0();
    virtual void Release();
};
class Root {
  public:
    void* vptr;
    ~Root() throw();
};
class D : public Root {
  public:
    char p40[60];
    Ref* a40;
    char p5c[24];
    Ref* a5c;
    Ref* a60;
    Ref* a64;
    ~D() throw();
};
D::~D() throw() {
    vptr = &vt1;
    _ReadWriteBarrier();
    if (a60) {
        a60->Release();
        a60 = 0;
    }
    if (a64) {
        a64->Release();
        a64 = 0;
    }
    vptr = &vt2;
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
