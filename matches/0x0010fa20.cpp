extern "C" void _ReadWriteBarrier();
extern void* g_vftable_10fa20[];
class Ref_10fa20 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_10fa20 {
  public:
    void* vptr;
    void Fin();
};
class SemaphoreClearAction_10fa20 : public Action_10fa20 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_10fa20* m20;
    ~SemaphoreClearAction_10fa20();
};
SemaphoreClearAction_10fa20::~SemaphoreClearAction_10fa20() {
    vptr = g_vftable_10fa20;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
