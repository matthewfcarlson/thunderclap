extern "C" void _ReadWriteBarrier();
extern void* g_vftable_151e40[];
class Ref_151e40 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_151e40 {
  public:
    void* vptr;
    void Fin();
};
class HitFloatAction_151e40 : public Base_151e40 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_151e40* m20;
    Ref_151e40* m24;
    ~HitFloatAction_151e40();
};
HitFloatAction_151e40::~HitFloatAction_151e40() {
    vptr = g_vftable_151e40;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
