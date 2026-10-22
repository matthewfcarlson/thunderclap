extern "C" void _ReadWriteBarrier();
extern void* g_vftable_199680[];
class Ref_199680 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_199680 {
  public:
    void* vptr;
    void Fin();
};
class MissilePunchAction_199680 : public Action_199680 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_199680* m20;
    ~MissilePunchAction_199680();
};
MissilePunchAction_199680::~MissilePunchAction_199680() {
    vptr = g_vftable_199680;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
