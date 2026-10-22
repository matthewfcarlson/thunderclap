extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2bb5c0[];
extern void* g_vftable2[];
class Ref_2bb5c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class SimpleChunkHandler_2bb5c0 {
  public:
    void* vptr;
};
class OldBillboardObjectLoader_2bb5c0 : public SimpleChunkHandler_2bb5c0 {
  public:
    char pad[0x10];
    Ref_2bb5c0* m;
    ~OldBillboardObjectLoader_2bb5c0();
};
OldBillboardObjectLoader_2bb5c0::~OldBillboardObjectLoader_2bb5c0() {
    vptr = g_vftable_2bb5c0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    vptr = g_vftable2;
}
