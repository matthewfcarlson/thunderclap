extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1268f0[];
class Ref_1268f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1268f0 {
  public:
    void* vptr;
    void Fin();
};
class TargetClearAction_1268f0 : public Base_1268f0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1268f0* m20;
    ~TargetClearAction_1268f0();
};
TargetClearAction_1268f0::~TargetClearAction_1268f0() {
    vptr = g_vftable_1268f0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
