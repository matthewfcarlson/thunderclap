extern "C" void _ReadWriteBarrier();
extern void* g_vftable_175d10[];
class Ref_175d10 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_175d10 {
  public:
    void* vptr;
    void Fin();
};
struct Vec_175d10 {
    int a;
    void Destroy();
};
class TeleportToLocatorAction_175d10 : public Action_175d10 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_175d10* m20;
    char pad2[4];
    Vec_175d10 m28;
    ~TeleportToLocatorAction_175d10();
};
TeleportToLocatorAction_175d10::~TeleportToLocatorAction_175d10() {
    vptr = g_vftable_175d10;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    m28.Destroy();
    Fin();
}
