extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2e1610[];
void operator delete(void*);
class Ref_2e1610 {
  public:
    virtual void F0();
    virtual void Release();
};
class RenderObjectLoader_2e1610 {
  public:
    void* vptr;
    void Fin();
};
class PrimGroupLoader_2e1610 : public RenderObjectLoader_2e1610 {
  public:
    char pad[4];
    Ref_2e1610* m;
    PrimGroupLoader_2e1610* f2(unsigned char flags);
};
PrimGroupLoader_2e1610* PrimGroupLoader_2e1610::f2(unsigned char flags) {
    vptr = g_vftable_2e1610;
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
