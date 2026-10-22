extern "C" void _ReadWriteBarrier();
extern void* g_vftable_20070[];
class Ref_20070 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_20070 {
  public:
    void* vptr;
    void Fin();
};
class CAction_20070 : public Action_20070 {
  public:
    char pad[24];
    Ref_20070* m;
    ~CAction_20070();
};
CAction_20070::~CAction_20070() {
    vptr = g_vftable_20070;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
