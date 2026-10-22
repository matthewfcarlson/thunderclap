extern "C" void _ReadWriteBarrier();
extern void* g_vA[];
class Ref_144930 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_144930 {
  public:
    void* vptr;
    void Fin();
};
class WorldDamageAction_144930 : public Action_144930 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_144930* m20;
    ~WorldDamageAction_144930() throw();
};
WorldDamageAction_144930::~WorldDamageAction_144930() throw() {
    vptr = g_vA;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
