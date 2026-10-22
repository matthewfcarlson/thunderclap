extern "C" void _ReadWriteBarrier();
extern void* g_vftable_20c10[];
class Ref_20c10 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_20c10 {
  public:
    void* vptr;
    void Fin();
};
class CAction_20c10 : public Action_20c10 {
  public:
    char pad[24];
    Ref_20c10* m;
    ~CAction_20c10();
};
CAction_20c10::~CAction_20c10() {
    vptr = g_vftable_20c10;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
