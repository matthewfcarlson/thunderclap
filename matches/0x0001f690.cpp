extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1f690[];
class Ref_1f690 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1f690 {
  public:
    void* vptr;
    void Fin();
};
class CAction_1f690 : public Action_1f690 {
  public:
    char pad[24];
    Ref_1f690* m;
    ~CAction_1f690();
};
CAction_1f690::~CAction_1f690() {
    vptr = g_vftable_1f690;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
