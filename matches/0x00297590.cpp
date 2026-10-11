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
    char p2c[40];
    Ref* a2c;
    ~D() throw();
};
D::~D() throw() {
    vptr = &vt1;
    _ReadWriteBarrier();
    if (a2c) {
        a2c->Release();
        a2c = 0;
    }
}
