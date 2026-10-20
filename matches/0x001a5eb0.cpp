extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1a5eb0[];
class Ref_1a5eb0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1a5eb0 {
  public:
    void* vptr;
    void Fin();
};
class EffectAction_1a5eb0 : public Base_1a5eb0 {
  public:
    char pad1c[0x18];
    void* m1c;
    Ref_1a5eb0* m20;
    char pad28[0x4];
    Ref_1a5eb0* m28;
    ~EffectAction_1a5eb0();
};
EffectAction_1a5eb0::~EffectAction_1a5eb0() {
    vptr = g_vftable_1a5eb0;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
