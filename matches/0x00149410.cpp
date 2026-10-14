extern "C" void _ReadWriteBarrier();
extern void* g_vftable_149410[];
class Ref_149410 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_149410 {
  public:
    void* vptr;
    void Fin();
};
class Action : public Base_149410 {
  public:
    char pad1c[0x18];
    void* m1c;
    Ref_149410* m20;
    ~Action();
};
Action::~Action() {
    vptr = g_vftable_149410;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
