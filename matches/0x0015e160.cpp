extern "C" void _ReadWriteBarrier();
extern void* g_vftable_15e160[];
extern void* g_vftable2[];
class Ref_15e160 {
  public:
    virtual void F0();
    virtual void Release();
};
class LocomotionStrafeAction_15e160 {
  public:
    void* vptr;
    void Fin();
};
class LocomotionStrafe4Action_15e160 : public LocomotionStrafeAction_15e160 {
  public:
    char p[0x18];
    Ref_15e160* m1c;
    Ref_15e160* m20;
    char p2[0x20];
    void* m44;
    ~LocomotionStrafe4Action_15e160() throw();
};
LocomotionStrafe4Action_15e160::~LocomotionStrafe4Action_15e160() throw() {
    vptr = g_vftable_15e160;
    _ReadWriteBarrier();
    if (m44)
        m44 = 0;
    vptr = g_vftable2;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
