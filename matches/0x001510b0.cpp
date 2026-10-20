extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1510b0[];
class Ref_1510b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1510b0 {
  public:
    void* vptr;
    void Fin();
};
class InterruptPriorityAction_1510b0 : public Base_1510b0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1510b0* m20;
    ~InterruptPriorityAction_1510b0();
};
InterruptPriorityAction_1510b0::~InterruptPriorityAction_1510b0() {
    vptr = g_vftable_1510b0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
