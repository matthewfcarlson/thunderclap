extern "C" void _ReadWriteBarrier();
extern void* g_vftable_151ee0[];
class Ref_151ee0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_151ee0 {
  public:
    void* vptr;
    void Fin();
};
class HitDamageAction_151ee0 : public Action_151ee0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_151ee0* m20;
    ~HitDamageAction_151ee0();
};
HitDamageAction_151ee0::~HitDamageAction_151ee0() {
    vptr = g_vftable_151ee0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
