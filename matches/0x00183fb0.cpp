extern "C" void _ReadWriteBarrier();
extern void* g_vftable_183fb0[];
class Ref_183fb0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_183fb0 {
  public:
    void* vptr;
    void Fin();
};
class PropDamageAction_183fb0 : public Action_183fb0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_183fb0* m20;
    ~PropDamageAction_183fb0();
};
PropDamageAction_183fb0::~PropDamageAction_183fb0() {
    vptr = g_vftable_183fb0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
