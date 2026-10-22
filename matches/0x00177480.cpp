extern "C" void _ReadWriteBarrier();
extern void* g_vftable_177480[];
class Ref_177480 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_177480 {
  public:
    void* vptr;
    void Fin();
};
class CriticalMassDrainAction_177480 : public Action_177480 {
  public:
    char pad1c[0x18];
    void* m1c;
    Ref_177480* m20;
    ~CriticalMassDrainAction_177480();
};
CriticalMassDrainAction_177480::~CriticalMassDrainAction_177480() {
    vptr = g_vftable_177480;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
