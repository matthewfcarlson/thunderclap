extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1169f0[];
class Ref_1169f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1169f0 {
  public:
    void* vptr;
    void Fin();
};
class MotionFacingAction_1169f0 : public Base_1169f0 {
  public:
    char pad1c[0x18];
    void* m1c;
    Ref_1169f0* m20;
    ~MotionFacingAction_1169f0();
};
MotionFacingAction_1169f0::~MotionFacingAction_1169f0() {
    vptr = g_vftable_1169f0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
