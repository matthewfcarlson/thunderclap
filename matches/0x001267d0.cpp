extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1267d0[];
class Ref_1267d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1267d0 {
  public:
    void* vptr;
    void Fin();
};
class AcquireTargetAction_1267d0 : public Base_1267d0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1267d0* m20;
    ~AcquireTargetAction_1267d0();
};
AcquireTargetAction_1267d0::~AcquireTargetAction_1267d0() {
    vptr = g_vftable_1267d0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
