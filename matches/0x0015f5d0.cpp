extern "C" void _ReadWriteBarrier();
extern void* g_vftable_15f5d0[];
extern void* g_vftable2[];
class Ref_15f5d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class ClimbLocomotionAction_15f5d0 {
  public:
    void* vptr;
    void Fin();
};
class ClimbLocomotion4Action_15f5d0 : public ClimbLocomotionAction_15f5d0 {
  public:
    char p[0x18];
    Ref_15f5d0* m1c;
    Ref_15f5d0* m20;
    Ref_15f5d0* m24;
    char p2[0x20];
    void* m48;
    ~ClimbLocomotion4Action_15f5d0() throw();
};
ClimbLocomotion4Action_15f5d0::~ClimbLocomotion4Action_15f5d0() throw() {
    vptr = g_vftable_15f5d0;
    _ReadWriteBarrier();
    if (m48)
        m48 = 0;
    vptr = g_vftable2;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
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
