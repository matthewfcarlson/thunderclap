extern "C" void _ReadWriteBarrier();
extern void* g_vftable_23f270[];
class Ref_23f270 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_23f270 {
  public:
    void* vptr;
    void Fin();
};
class BreakPointAction_23f270 : public Action_23f270 {
  public:
    char pad[28];
    Ref_23f270* m;
    ~BreakPointAction_23f270();
};
BreakPointAction_23f270::~BreakPointAction_23f270() {
    vptr = g_vftable_23f270;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
