extern "C" void _ReadWriteBarrier();
extern void* g_vftable_15e780[];
class Ref_15e780 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_15e780 {
  public:
    void* vptr;
    void Fin();
};
class LocomotionSteerAction_15e780 : public Base_15e780 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_15e780* m20;
    Ref_15e780* m24;
    ~LocomotionSteerAction_15e780();
};
LocomotionSteerAction_15e780::~LocomotionSteerAction_15e780() {
    vptr = g_vftable_15e780;
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
