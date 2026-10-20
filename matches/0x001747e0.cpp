extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1747e0[];
class Ref_1747e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1747e0 {
  public:
    void* vptr;
    void Fin();
};
class ChargeAction_1747e0 : public Base_1747e0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1747e0* m20;
    ~ChargeAction_1747e0();
};
ChargeAction_1747e0::~ChargeAction_1747e0() {
    vptr = g_vftable_1747e0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
