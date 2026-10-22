extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2b6fb0[];
extern void* g_vftable2[];
void operator delete(void*);
class Ref_2b6fb0 {
  public:
    virtual void F0();
    virtual void Release();
};
class DrawablePrimitive_2b6fb0 {
  public:
    void* vptr;
    void Fin();
};
class ShadowMeshBufferImpl_2b6fb0 : public DrawablePrimitive_2b6fb0 {
  public:
    char pad[0x3c];
    Ref_2b6fb0* m;
    ShadowMeshBufferImpl_2b6fb0* f2(unsigned char flags);
};
ShadowMeshBufferImpl_2b6fb0* ShadowMeshBufferImpl_2b6fb0::f2(unsigned char flags) {
    vptr = g_vftable_2b6fb0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
