extern "C" void _ReadWriteBarrier();
extern void* g_vftable_144c80[];
class Ref_144c80 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_144c80 {
  public:
    void* vptr;
    void Fin();
};
class Action : public Base_144c80 {
  public:
    char pad[0x18];
    Ref_144c80* m1c;
    void* m20;
    Ref_144c80* m24;
    ~Action();
};
Action::~Action() {
    vptr = g_vftable_144c80;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20)
        m20 = 0;
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
