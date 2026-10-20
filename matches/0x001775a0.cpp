extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1775a0[];
class Ref_1775a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1775a0 {
  public:
    void* vptr;
    void Fin();
};
class VisibilityAction_1775a0 : public Base_1775a0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1775a0* m20;
    ~VisibilityAction_1775a0();
};
VisibilityAction_1775a0::~VisibilityAction_1775a0() {
    vptr = g_vftable_1775a0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
