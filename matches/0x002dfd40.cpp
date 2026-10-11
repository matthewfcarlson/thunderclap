extern void* g_vftable[];
extern "C" void _ReadWriteBarrier();
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Base {
  public:
    void* vptr;
    void Fin();
};
class Action : public Base {
  public:
    char pad[0x3c];
    Ref* m40;
    ~Action();
};
Action::~Action() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m40) {
        m40->Release();
        m40 = 0;
    }
    Fin();
}
