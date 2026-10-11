extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Sub {
  public:
    void Fini();
};
class Base {
  public:
    void* vptr;
    void Fin();
};
class Action : public Base {
  public:
    char pad[0x18];
    Ref* m1c;
    char pad2[8];
    Ref* m28;
    Sub m2c;
    ~Action();
};
Action::~Action() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    m2c.Fini();
    Fin();
}
