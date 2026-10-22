extern "C" void _ReadWriteBarrier();
extern void* g_vftable_151c20[];
class Ref_151c20 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_151c20 {
  public:
    void* vptr;
    void Fin();
};
class HitPushbackAction_151c20 : public Action_151c20 {
  public:
    char pad1c[0x18];
    void* m1c;
    Ref_151c20* m20;
    Ref_151c20* m24;
    ~HitPushbackAction_151c20();
};
HitPushbackAction_151c20::~HitPushbackAction_151c20() {
    vptr = g_vftable_151c20;
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
