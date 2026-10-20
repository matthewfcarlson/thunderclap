extern "C" void _ReadWriteBarrier();
extern void* g_vftable_174750[];
class Ref_174750 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_174750 {
  public:
    void* vptr;
    void Fin();
};
class IntentionClearAction_174750 : public Base_174750 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_174750* m20;
    ~IntentionClearAction_174750();
};
IntentionClearAction_174750::~IntentionClearAction_174750() {
    vptr = g_vftable_174750;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
