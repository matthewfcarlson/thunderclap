extern "C" void _ReadWriteBarrier();
extern void* g_vftable_184040[];
class Ref_184040 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_184040 {
  public:
    void* vptr;
    void Fin();
};
class Action : public Base_184040 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_184040* m20;
    ~Action();
};
Action::~Action() {
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
