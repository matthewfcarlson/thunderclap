extern "C" void _ReadWriteBarrier();
extern void* g_vftable_0042fb84[];
class Ref_2e13b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class RenderObjectLoader_2e13b0 {
  public:
    void* vptr;
    void Fin();
};
class PrimGroupLoader_2e13b0 : public RenderObjectLoader_2e13b0 {
  public:
    char pad[4];
    Ref_2e13b0* m;
    ~PrimGroupLoader_2e13b0();
};
PrimGroupLoader_2e13b0::~PrimGroupLoader_2e13b0() {
    vptr = g_vftable_0042fb84;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
