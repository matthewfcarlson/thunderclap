extern "C" void _ReadWriteBarrier();
extern void* g_vftable_10ec50[];
class Ref_10ec50 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_10ec50 {
  public:
    void* vptr;
    void Fin();
};
class ButtonAction_10ec50 : public Action_10ec50 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_10ec50* m20;
    ~ButtonAction_10ec50();
};
ButtonAction_10ec50::~ButtonAction_10ec50() {
    vptr = g_vftable_10ec50;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
