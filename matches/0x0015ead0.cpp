extern "C" void _ReadWriteBarrier();
extern void* g_vftable_15ead0[];
class Ref_15ead0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_15ead0 {
  public:
    void* vptr;
    void Fin();
};
class GrappleLocomotionSteerAction_15ead0 : public Base_15ead0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_15ead0* m20;
    Ref_15ead0* m24;
    ~GrappleLocomotionSteerAction_15ead0();
};
GrappleLocomotionSteerAction_15ead0::~GrappleLocomotionSteerAction_15ead0() {
    vptr = g_vftable_15ead0;
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
