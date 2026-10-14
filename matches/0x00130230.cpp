extern "C" void _ReadWriteBarrier();
extern void* g_vftable_130230[];
class Ref_130230 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_130230 {
  public:
    void* vptr;
    void Fin();
};
class Action : public Base_130230 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_130230* m20;
    ~Action();
};
Action::~Action() {
    vptr = g_vftable_130230;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
