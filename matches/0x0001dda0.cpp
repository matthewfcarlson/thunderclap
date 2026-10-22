extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1dda0[];
class Ref_1dda0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1dda0 {
  public:
    void* vptr;
    void Fin();
};
class CAction_1dda0 : public Action_1dda0 {
  public:
    char pad1c[0x18];
    Ref_1dda0* m1c;
    ~CAction_1dda0();
};
CAction_1dda0::~CAction_1dda0() {
    vptr = g_vftable_1dda0;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
