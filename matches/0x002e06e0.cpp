extern "C" void _ReadWriteBarrier();
extern int vt1_2e06e0;
class Ref_2e06e0 {
  public:
    virtual void f0();
    virtual void Release();
};
class Base_2e06e0 {
  public:
    void* vptr;
    char pad[0x64];
    Ref_2e06e0* child;
    ~Base_2e06e0() throw();
};
class D : public Base_2e06e0 {
  public:
    ~D() throw();
};
D::~D() throw() {
    vptr = &vt1_2e06e0;
    _ReadWriteBarrier();
    if (child) {
        child->Release();
        child = 0;
    }
}
