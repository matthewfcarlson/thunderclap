extern "C" void _ReadWriteBarrier();
extern void* g_a_2c3160[];
extern void* g_b_2c3160[];
void operator delete(void*);
class Ref_2c3160 {
  public:
    virtual void F0();
    virtual void Release();
};
class GeometryLoader_2c3160 {
  public:
    void* vptr;
    char pad[0x18];
    Ref_2c3160* m1c;
    Ref_2c3160* m20;
    GeometryLoader_2c3160* f2(unsigned char flags);
};
GeometryLoader_2c3160* GeometryLoader_2c3160::f2(unsigned char flags) {
    vptr = g_a_2c3160;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    vptr = g_b_2c3160;
    if (flags & 1)
        operator delete(this);
    return this;
}
