extern "C" void _ReadWriteBarrier();
extern void* g_vftable_10fab0[];
class Ref_10fab0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_10fab0 {
  public:
    void* vptr;
    void Fin();
};
class KeywordWaitAction_10fab0 : public Base_10fab0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_10fab0* m20;
    ~KeywordWaitAction_10fab0();
};
KeywordWaitAction_10fab0::~KeywordWaitAction_10fab0() {
    vptr = g_vftable_10fab0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
