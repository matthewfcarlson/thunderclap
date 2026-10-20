extern "C" void _ReadWriteBarrier();
extern void* g_vftable_10f870[];
class Ref_10f870 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_10f870 {
  public:
    void* vptr;
    void Fin();
};
class TokenAction_10f870 : public Base_10f870 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_10f870* m20;
    ~TokenAction_10f870();
};
TokenAction_10f870::~TokenAction_10f870() {
    vptr = g_vftable_10f870;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
