extern "C" void _ReadWriteBarrier();
extern void* g_vftable_183e00[];
class Ref_183e00 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_183e00 {
  public:
    void* vptr;
    void Fin();
};
class Action : public Base_183e00 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_183e00* m20;
    ~Action();
};
Action::~Action() {
    vptr = g_vftable_183e00;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
