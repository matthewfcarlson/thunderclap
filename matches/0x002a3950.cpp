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
    char pa4[160];
    Ref* aa4;
    Ref* aa8;
    ~D() throw();
};
D::~D() throw() {
    vptr = &vt1;
    _ReadWriteBarrier();
    if (aa4) {
        aa4->Release();
        aa4 = 0;
    }
    if (aa8) {
        aa8->Release();
        aa8 = 0;
    }
}
