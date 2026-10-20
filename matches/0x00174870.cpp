extern "C" void _ReadWriteBarrier();
extern void* g_vftable_174870[];
class Ref_174870 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_174870 {
  public:
    void* vptr;
    void Fin();
};
class ChargeClearAction_174870 : public Base_174870 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_174870* m20;
    ~ChargeClearAction_174870();
};
ChargeClearAction_174870::~ChargeClearAction_174870() {
    vptr = g_vftable_174870;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
