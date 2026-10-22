extern "C" void _ReadWriteBarrier();
extern void* g_vftable_18d660[];
class Ref_18d660 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_18d660 {
  public:
    void* vptr;
    void Fin();
};
class TimerSetAction_18d660 : public Action_18d660 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_18d660* m20;
    ~TimerSetAction_18d660();
};
TimerSetAction_18d660::~TimerSetAction_18d660() {
    vptr = g_vftable_18d660;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
