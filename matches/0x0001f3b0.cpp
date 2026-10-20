extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1f3b0[];
class Ref_1f3b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1f3b0 {
  public:
    void* vptr;
    void Fin();
};
class CAction_1f3b0 : public Base_1f3b0 {
  public:
    char pad[0x18];
    Ref_1f3b0* m1c;
    ~CAction_1f3b0();
};
CAction_1f3b0::~CAction_1f3b0() {
    vptr = g_vftable_1f3b0;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
