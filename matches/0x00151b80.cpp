extern "C" void _ReadWriteBarrier();
extern void* g_vftable_151b80[];
class Ref_151b80 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_151b80 {
  public:
    void* vptr;
    void Fin();
};
class NoHitPushbackAction_151b80 : public Action_151b80 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_151b80* m20;
    ~NoHitPushbackAction_151b80();
};
NoHitPushbackAction_151b80::~NoHitPushbackAction_151b80() {
    vptr = g_vftable_151b80;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
