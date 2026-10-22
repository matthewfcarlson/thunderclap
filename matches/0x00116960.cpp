extern "C" void _ReadWriteBarrier();
extern void* g_vftable_116960[];
class Ref_116960 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_116960 {
  public:
    void* vptr;
    void Fin();
};
class MotionStopAction_116960 : public Action_116960 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_116960* m20;
    ~MotionStopAction_116960();
};
MotionStopAction_116960::~MotionStopAction_116960() {
    vptr = g_vftable_116960;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
