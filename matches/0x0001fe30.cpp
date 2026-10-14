extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1fe30[];
class Ref_1fe30 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1fe30 {
  public:
    void* vptr;
    void Fin();
};
class Action : public Base_1fe30 {
  public:
    char pad[0x18];
    Ref_1fe30* m1c;
    ~Action();
};
Action::~Action() {
    vptr = g_vftable_1fe30;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
