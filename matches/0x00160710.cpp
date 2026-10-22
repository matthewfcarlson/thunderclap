extern "C" void _ReadWriteBarrier();
extern void* g_vA[];
class Ref_160710 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_160710 {
  public:
    void* vptr;
    void Fin();
};
class LocomotingAction_160710 : public Action_160710 {
  public:
    char pad[24];
    Ref_160710* m;
    ~LocomotingAction_160710() throw();
};
LocomotingAction_160710::~LocomotingAction_160710() throw() {
    vptr = g_vA;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
