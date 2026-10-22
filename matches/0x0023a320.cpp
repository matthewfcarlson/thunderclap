extern "C" void _ReadWriteBarrier();
extern void* g_vftable_23a320[];
class Ref_23a320 {
  public:
    virtual void F0();
    virtual void Release();
};
class Sub_23a320 {
  public:
    void Fini();
};
class Action_23a320 {
  public:
    void* vptr;
    void Fin();
};
class QueuedNodeAction_23a320 : public Action_23a320 {
  public:
    char pad[0x18];
    Ref_23a320* m1c;
    char pad2[8];
    Ref_23a320* m28;
    Sub_23a320 m2c;
    ~QueuedNodeAction_23a320();
};
QueuedNodeAction_23a320::~QueuedNodeAction_23a320() {
    vptr = g_vftable_23a320;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    m2c.Fini();
    Fin();
}
