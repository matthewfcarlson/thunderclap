extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1511d0[];
class Ref_1511d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1511d0 {
  public:
    void* vptr;
    void Fin();
};
class Action : public Base_1511d0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1511d0* m20;
    Ref_1511d0* m24;
    ~Action();
};
Action::~Action() {
    vptr = g_vftable_1511d0;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
