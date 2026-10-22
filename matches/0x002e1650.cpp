extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2e1650[];
void operator delete(void*);
class Ref_2e1650 {
  public:
    virtual void F0();
    virtual void Release();
};
class RenderObjectLoader_2e1650 {
  public:
    void* vptr;
    void Fin();
};
class OldPrimGroupLoader_2e1650 : public RenderObjectLoader_2e1650 {
  public:
    char pad[4];
    Ref_2e1650* m;
    OldPrimGroupLoader_2e1650* f2(unsigned char flags);
};
OldPrimGroupLoader_2e1650* OldPrimGroupLoader_2e1650::f2(unsigned char flags) {
    vptr = g_vftable_2e1650;
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
