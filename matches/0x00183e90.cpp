extern "C" void _ReadWriteBarrier();
extern void* g_vftable_183e90[];
class Ref_183e90 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_183e90 {
  public:
    void* vptr;
    void Fin();
};
class PropSpawnAction_183e90 : public Base_183e90 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_183e90* m20;
    ~PropSpawnAction_183e90();
};
PropSpawnAction_183e90::~PropSpawnAction_183e90() {
    vptr = g_vftable_183e90;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
