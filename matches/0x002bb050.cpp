extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2bb050[];
extern void* g_base_2bb050[];
class Ref_2bb050 {
  public:
    virtual void F0();
    virtual void Release();
};
class BillboardObjectLoader_2bb050 {
  public:
    void* vptr;
    char pad[0x10];
    Ref_2bb050* m14;
    ~BillboardObjectLoader_2bb050();
};
BillboardObjectLoader_2bb050::~BillboardObjectLoader_2bb050() {
    vptr = g_vftable_2bb050;
    _ReadWriteBarrier();
    if (m14) {
        m14->Release();
        m14 = 0;
    }
    vptr = g_base_2bb050;
}
