extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1f5a0[];
class Ref_1f5a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1f5a0 {
  public:
    void* vptr;
    void Fin();
};
class CAction_1f5a0 : public Action_1f5a0 {
  public:
    char pad[24];
    Ref_1f5a0* m;
    ~CAction_1f5a0();
};
CAction_1f5a0::~CAction_1f5a0() {
    vptr = g_vftable_1f5a0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
