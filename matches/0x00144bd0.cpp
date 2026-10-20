extern "C" void _ReadWriteBarrier();
extern void* g_vftable_144bd0[];
class Ref_144bd0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_144bd0 {
  public:
    void* vptr;
    void Fin();
};
class MotionTrailStopAction_144bd0 : public Base_144bd0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_144bd0* m20;
    ~MotionTrailStopAction_144bd0();
};
MotionTrailStopAction_144bd0::~MotionTrailStopAction_144bd0() {
    vptr = g_vftable_144bd0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
