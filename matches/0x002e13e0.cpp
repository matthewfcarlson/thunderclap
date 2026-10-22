extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2e13e0[];
class Ref_2e13e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class RenderObjectLoader_2e13e0 {
  public:
    void* vptr;
    void Fin();
};
class OldPrimGroupLoader_2e13e0 : public RenderObjectLoader_2e13e0 {
  public:
    char pad[4];
    Ref_2e13e0* m;
    ~OldPrimGroupLoader_2e13e0();
};
OldPrimGroupLoader_2e13e0::~OldPrimGroupLoader_2e13e0() {
    vptr = g_vftable_2e13e0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
