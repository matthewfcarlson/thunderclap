extern "C" void _ReadWriteBarrier();
extern void* g_vftable_215a0[];
class Ref_215a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_215a0 {
  public:
    void* vptr;
    void Fin();
};
class CAction_215a0 : public Action_215a0 {
  public:
    char pad[24];
    Ref_215a0* m;
    ~CAction_215a0();
};
CAction_215a0::~CAction_215a0() {
    vptr = g_vftable_215a0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
