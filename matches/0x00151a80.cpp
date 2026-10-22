extern "C" void _ReadWriteBarrier();
extern void* g_vftable_151a80[];
class Ref_151a80 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_151a80 {
  public:
    void* vptr;
    void Fin();
};
class HitPushbackAddAction_151a80 : public Action_151a80 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_151a80* m20;
    ~HitPushbackAddAction_151a80();
};
HitPushbackAddAction_151a80::~HitPushbackAddAction_151a80() {
    vptr = g_vftable_151a80;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
