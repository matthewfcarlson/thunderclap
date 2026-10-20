extern void* g_vftable_10f7e0[];
extern "C" void _ReadWriteBarrier();
class Ref_10f7e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_10f7e0 {
  public:
    void* vptr;
    void Fin();
};
class TokenSupressAction_10f7e0 : public Base_10f7e0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_10f7e0* m20;
    ~TokenSupressAction_10f7e0();
};
TokenSupressAction_10f7e0::~TokenSupressAction_10f7e0() {
    vptr = g_vftable_10f7e0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
