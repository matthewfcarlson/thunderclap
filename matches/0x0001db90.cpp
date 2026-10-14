extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1db90[];
class Ref_1db90 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1db90 {
  public:
    void* vptr;
    void Fin();
};
class Action : public Base_1db90 {
  public:
    char pad1c[0x18];
    Ref_1db90* m1c;
    ~Action();
};
Action::~Action() {
    vptr = g_vftable_1db90;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
