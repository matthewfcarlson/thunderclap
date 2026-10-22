extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1364f0[];
class Ref_1364f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1364f0 {
  public:
    void* vptr;
    void Fin();
};
class BounceAction_1364f0 : public Action_1364f0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1364f0* m20;
    Ref_1364f0* m24;
    ~BounceAction_1364f0();
};
BounceAction_1364f0::~BounceAction_1364f0() {
    vptr = g_vftable_1364f0;
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
