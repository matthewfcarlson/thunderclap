extern "C" void _ReadWriteBarrier();
extern void* g_vftable_20d20[];
class Ref_20d20 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_20d20 {
  public:
    void* vptr;
    void Fin();
};
class CAction_20d20 : public Action_20d20 {
  public:
    char pad[24];
    Ref_20d20* m;
    ~CAction_20d20();
};
CAction_20d20::~CAction_20d20() {
    vptr = g_vftable_20d20;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
