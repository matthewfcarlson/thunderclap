extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1ae10[];
class Ref_1ae10 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1ae10 {
  public:
    void* vptr;
    void Fin();
};
class CAction_1ae10 : public Action_1ae10 {
  public:
    char pad[24];
    Ref_1ae10* m;
    ~CAction_1ae10();
};
CAction_1ae10::~CAction_1ae10() {
    vptr = g_vftable_1ae10;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
