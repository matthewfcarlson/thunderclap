extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1f850[];
class Ref_1f850 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1f850 {
  public:
    void* vptr;
    void Fin();
};
class CAction_1f850 : public Action_1f850 {
  public:
    char pad[24];
    Ref_1f850* m;
    ~CAction_1f850();
};
CAction_1f850::~CAction_1f850() {
    vptr = g_vftable_1f850;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
