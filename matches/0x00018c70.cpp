extern "C" void _ReadWriteBarrier();
extern void* g_vftable_18c70[];
class Ref_18c70 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_18c70 {
  public:
    void* vptr;
    void Fin();
};
class CAction_18c70 : public Action_18c70 {
  public:
    char pad[24];
    Ref_18c70* m;
    ~CAction_18c70();
};
CAction_18c70::~CAction_18c70() {
    vptr = g_vftable_18c70;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
