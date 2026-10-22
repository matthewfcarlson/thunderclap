extern "C" void _ReadWriteBarrier();
extern void* g_vftable_20b20[];
class Ref_20b20 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_20b20 {
  public:
    void* vptr;
    void Fin();
};
class CAction_20b20 : public Action_20b20 {
  public:
    char pad[24];
    Ref_20b20* m;
    ~CAction_20b20();
};
CAction_20b20::~CAction_20b20() {
    vptr = g_vftable_20b20;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
