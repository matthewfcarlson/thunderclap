extern "C" void _ReadWriteBarrier();
extern void* g_vftable_176020[];
class Ref_176020 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_176020 {
  public:
    void* vptr;
    void Fin();
};
class SuckInPropsAction_176020 : public Action_176020 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_176020* m20;
    ~SuckInPropsAction_176020();
};
SuckInPropsAction_176020::~SuckInPropsAction_176020() {
    vptr = g_vftable_176020;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
