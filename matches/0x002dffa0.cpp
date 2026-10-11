extern "C" void _ReadWriteBarrier();
extern int vt1;
extern int vt2;
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
    char p58[20];
    Ref* a58;
    ~D() throw();
};
D::~D() throw() {
    vptr = &vt1;
    _ReadWriteBarrier();
    if (a58) {
        a58->Release();
        a58 = 0;
    }
    vptr = &vt2;
    _ReadWriteBarrier();
    if (a40) {
        a40->Release();
        a40 = 0;
    }
}
