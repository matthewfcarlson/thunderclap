extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1839a0[];
class Ref_1839a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1839a0 {
  public:
    void* vptr;
    void Fin();
};
class PropActorToPropAction_1839a0 : public Base_1839a0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1839a0* m20;
    ~PropActorToPropAction_1839a0();
};
PropActorToPropAction_1839a0::~PropActorToPropAction_1839a0() {
    vptr = g_vftable_1839a0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
