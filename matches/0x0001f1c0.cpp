extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1f1c0[];
class Ref_1f1c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1f1c0 {
  public:
    void* vptr;
    void Fin();
};
class CAction_1f1c0 : public Action_1f1c0 {
  public:
    char pad[24];
    Ref_1f1c0* m;
    ~CAction_1f1c0();
};
CAction_1f1c0::~CAction_1f1c0() {
    vptr = g_vftable_1f1c0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
