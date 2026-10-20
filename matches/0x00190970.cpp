extern "C" void _ReadWriteBarrier();
extern void* g_vftable_190970[];
class Ref_190970 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_190970 {
  public:
    void* vptr;
    void Fin();
};
class SimulationAction_190970 : public Base_190970 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_190970* m20;
    ~SimulationAction_190970();
};
SimulationAction_190970::~SimulationAction_190970() {
    vptr = g_vftable_190970;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
