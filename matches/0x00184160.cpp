extern "C" void _ReadWriteBarrier();
extern void* g_vftable_184160[];
class Ref_184160 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_184160 {
  public:
    void* vptr;
    void Fin();
};
class PropThrowAction_184160 : public Base_184160 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_184160* m20;
    ~PropThrowAction_184160();
};
PropThrowAction_184160::~PropThrowAction_184160() {
    vptr = g_vftable_184160;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
