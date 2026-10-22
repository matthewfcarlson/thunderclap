extern "C" void _ReadWriteBarrier();
extern void* g_vftable_183cf0[];
class Ref_183cf0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_183cf0 {
  public:
    void* vptr;
    void Fin();
};
class PropSetStateByIndexAction_183cf0 : public Action_183cf0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_183cf0* m20;
    ~PropSetStateByIndexAction_183cf0();
};
PropSetStateByIndexAction_183cf0::~PropSetStateByIndexAction_183cf0() {
    vptr = g_vftable_183cf0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
