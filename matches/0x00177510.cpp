extern "C" void _ReadWriteBarrier();
extern void* g_vftable_177510[];
class Ref_177510 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_177510 {
  public:
    void* vptr;
    void Fin();
};
class MomentumXZAddAction_177510 : public Base_177510 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_177510* m20;
    ~MomentumXZAddAction_177510();
};
MomentumXZAddAction_177510::~MomentumXZAddAction_177510() {
    vptr = g_vftable_177510;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
