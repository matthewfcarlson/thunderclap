extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1f610[];
class Ref_1f610 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1f610 {
  public:
    void* vptr;
    void Fin();
};
class Action : public Base_1f610 {
  public:
    char pad1c[0x18];
    Ref_1f610* m1c;
    ~Action();
};
Action::~Action() {
    vptr = g_vftable_1f610;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
