extern "C" void _ReadWriteBarrier();
extern void* g_vA[];
class Ref_183c60 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_183c60 {
  public:
    void* vptr;
    void Fin();
};
class PropAddToCollisionAction_183c60 : public Action_183c60 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_183c60* m20;
    ~PropAddToCollisionAction_183c60() throw();
};
PropAddToCollisionAction_183c60::~PropAddToCollisionAction_183c60() throw() {
    vptr = g_vA;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
