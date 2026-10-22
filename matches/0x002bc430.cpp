extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2bc430[];
extern void* g_base_vftable[];
void operator delete(void*);
class Ref_2bc430 {
  public:
    virtual void F0();
    virtual void Release();
};
class SimpleChunkHandler_2bc430 {
  public:
    void* vptr;
};
class BillboardObjectLoader_2bc430 : public SimpleChunkHandler_2bc430 {
  public:
    char pad[0x10];
    Ref_2bc430* m14;
    BillboardObjectLoader_2bc430* f2(unsigned char flags);
};
BillboardObjectLoader_2bc430* BillboardObjectLoader_2bc430::f2(unsigned char flags) {
    vptr = g_vftable_2bc430;
    _ReadWriteBarrier();
    if (m14) {
        m14->Release();
        m14 = 0;
    }
    vptr = g_base_vftable;
    if (flags & 1)
        operator delete(this);
    return this;
}
