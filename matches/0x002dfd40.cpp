extern void* g_vftable_2dfd40[];
extern "C" void _ReadWriteBarrier();
class Ref_2dfd40 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_2dfd40 {
  public:
    void* vptr;
    void Fin();
};
class Action : public Base_2dfd40 {
  public:
    char pad[0x3c];
    Ref_2dfd40* m40;
    ~Action();
};
Action::~Action() {
    vptr = g_vftable_2dfd40;
    _ReadWriteBarrier();
    if (m40) {
        m40->Release();
        m40 = 0;
    }
    Fin();
}
