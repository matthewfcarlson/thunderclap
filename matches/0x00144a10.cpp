extern "C" void _ReadWriteBarrier();
extern void* g_vftable_144a10[];
class Ref_144a10 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_144a10 {
  public:
    void* vptr;
    void Fin();
};
class WorldConeDamageAction_144a10 : public Base_144a10 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_144a10* m20;
    ~WorldConeDamageAction_144a10();
};
WorldConeDamageAction_144a10::~WorldConeDamageAction_144a10() {
    vptr = g_vftable_144a10;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
