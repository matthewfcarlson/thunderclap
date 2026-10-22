extern "C" void _ReadWriteBarrier();
extern void* g_vftable_20b90[];
class Ref_20b90 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_20b90 {
  public:
    void* vptr;
    void Fin();
};
class CAction_20b90 : public Action_20b90 {
  public:
    char pad[24];
    Ref_20b90* m;
    ~CAction_20b90();
};
CAction_20b90::~CAction_20b90() {
    vptr = g_vftable_20b90;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
