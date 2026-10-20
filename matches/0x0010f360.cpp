extern "C" void _ReadWriteBarrier();
extern void* g_vftable_10f360[];
class Ref_10f360 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_10f360 {
  public:
    void* vptr;
    void Fin();
};
class HulkAction_10f360 : public Base_10f360 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_10f360* m20;
    ~HulkAction_10f360();
};
HulkAction_10f360::~HulkAction_10f360() {
    vptr = g_vftable_10f360;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
