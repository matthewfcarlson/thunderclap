extern "C" void _ReadWriteBarrier();
extern void* g_vftable_183f20[];
class Ref_183f20 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_183f20 {
  public:
    void* vptr;
    void Fin();
};
class PropDropAction_183f20 : public Base_183f20 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_183f20* m20;
    ~PropDropAction_183f20();
};
PropDropAction_183f20::~PropDropAction_183f20() {
    vptr = g_vftable_183f20;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
