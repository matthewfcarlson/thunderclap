extern "C" void _ReadWriteBarrier();
extern void* g_vt[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Base {
  public:
    void* vptr;
    ~Base() throw();
};
class A : public Base {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref* m20;
    ~A() throw();
};
A::~A() throw() {
    vptr = g_vt;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
}
