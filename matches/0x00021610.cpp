extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21610[];
class Ref_21610 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_21610 {
  public:
    void* vptr;
    void Fin();
};
class CAction_21610 : public Action_21610 {
  public:
    char pad[24];
    Ref_21610* m;
    ~CAction_21610();
};
CAction_21610::~CAction_21610() {
    vptr = g_vftable_21610;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
