extern "C" void _ReadWriteBarrier();
extern void* g_vftable_130110[];
class Ref_130110 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_130110 {
  public:
    void* vptr;
    void Fin();
};
class StatBeginTrialAction_130110 : public Action_130110 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_130110* m20;
    ~StatBeginTrialAction_130110();
};
StatBeginTrialAction_130110::~StatBeginTrialAction_130110() {
    vptr = g_vftable_130110;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
