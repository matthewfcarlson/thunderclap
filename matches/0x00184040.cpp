extern "C" void _ReadWriteBarrier();
extern void* g_vftable_184040[];
class Ref_184040 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_184040 {
  public:
    void* vptr;
    void Fin();
};
class GrapplePropDamageAction_184040 : public Action_184040 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_184040* m20;
    ~GrapplePropDamageAction_184040();
};
GrapplePropDamageAction_184040::~GrapplePropDamageAction_184040() {
    vptr = g_vftable_184040;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
