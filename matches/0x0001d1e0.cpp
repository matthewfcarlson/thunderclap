extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1d1e0[];
class Ref_1d1e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1d1e0 {
  public:
    void* vptr;
    void Fin();
};
class CAction_1d1e0 : public Action_1d1e0 {
  public:
    char pad[24];
    Ref_1d1e0* m;
    ~CAction_1d1e0();
};
CAction_1d1e0::~CAction_1d1e0() {
    vptr = g_vftable_1d1e0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
