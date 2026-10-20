extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1f8d0[];
class Ref_1f8d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1f8d0 {
  public:
    void* vptr;
    void Fin();
};
class CAction_1f8d0 : public Base_1f8d0 {
  public:
    char pad1c[0x18];
    Ref_1f8d0* m1c;
    ~CAction_1f8d0();
};
CAction_1f8d0::~CAction_1f8d0() {
    vptr = g_vftable_1f8d0;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
