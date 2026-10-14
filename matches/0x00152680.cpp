extern "C" void _ReadWriteBarrier();
extern void* g_vftable_152680[];
class Ref_152680 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_152680 {
  public:
    void* vptr;
    void Fin();
};
class Action : public Base_152680 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_152680* m20;
    ~Action();
};
Action::~Action() {
    vptr = g_vftable_152680;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
