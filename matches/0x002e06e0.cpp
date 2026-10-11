extern "C" void _ReadWriteBarrier();
extern int vt1;
class Ref {
  public:
    virtual void f0();
    virtual void Release();
};
class Base {
  public:
    void* vptr;
    char pad[0x64];
    Ref* child;
    ~Base() throw();
};
class D : public Base {
  public:
    ~D() throw();
};
D::~D() throw() {
    vptr = &vt1;
    _ReadWriteBarrier();
    if (child) {
        child->Release();
        child = 0;
    }
}
