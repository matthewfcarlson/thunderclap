extern "C" void _ReadWriteBarrier();
extern int vt1;
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
    char p58[84];
    Ref* a58;
    Ref* a5c;
    Ref* a60;
    Ref* a64;
    ~D() throw();
};
D::~D() throw() {
    vptr = &vt1;
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
