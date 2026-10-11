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
    char pad[0x18];
    void* m1c;
    Ref* m20;
    ~Action();
};
Action::~Action() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
