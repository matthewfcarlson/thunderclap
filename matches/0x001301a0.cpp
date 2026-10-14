extern "C" void _ReadWriteBarrier();
extern void* g_vt_1301a0[];
class Ref_1301a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1301a0 {
  public:
    void* vptr;
    ~Base_1301a0() throw();
};
class A_1301a0 : public Base_1301a0 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_1301a0* m20;
    ~A_1301a0() throw();
};
A_1301a0::~A_1301a0() throw() {
    vptr = g_vt_1301a0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
}
