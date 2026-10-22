extern "C" void _ReadWriteBarrier();
extern void* g_vftable_116a80[];
class Ref_116a80 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_116a80 {
  public:
    void* vptr;
    void Fin();
};
class MotionTargetAction_116a80 : public Action_116a80 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_116a80* m20;
    Ref_116a80* m24;
    ~MotionTargetAction_116a80();
};
MotionTargetAction_116a80::~MotionTargetAction_116a80() {
    vptr = g_vftable_116a80;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
