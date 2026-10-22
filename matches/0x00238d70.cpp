extern "C" void _ReadWriteBarrier();
extern void* g_vA[];
class Ref_238d70 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_238d70 {
  public:
    void* vptr;
    void Fin();
};
class PrintAction_238d70 : public Action_238d70 {
  public:
    char pad[28];
    Ref_238d70* m;
    ~PrintAction_238d70() throw();
};
PrintAction_238d70::~PrintAction_238d70() throw() {
    vptr = g_vA;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
