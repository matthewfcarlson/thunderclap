extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2b6890[];
class Ref_2b6890 {
  public:
    virtual void F0();
    virtual void Release();
};
class DrawablePrimitive_2b6890 {
  public:
    void* vptr;
    void Fin();
};
class ShadowMeshBufferImpl_2b6890 : public DrawablePrimitive_2b6890 {
  public:
    char pad[60];
    Ref_2b6890* m;
    ~ShadowMeshBufferImpl_2b6890();
};
ShadowMeshBufferImpl_2b6890::~ShadowMeshBufferImpl_2b6890() {
    vptr = g_vftable_2b6890;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
