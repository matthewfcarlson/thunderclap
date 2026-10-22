extern "C" void _ReadWriteBarrier();
extern void* g_vftable_222c0[];
void operator delete(void*);
class Ref_222c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_222c0 {
  public:
    void* vptr;
    void Fin();
};
class CCameraDramaticAction_222c0 : public CAction_222c0 {
  public:
    char pad[0x1c - 4];
    Ref_222c0* m;
    CCameraDramaticAction_222c0* f2(unsigned char flags);
};
CCameraDramaticAction_222c0* CCameraDramaticAction_222c0::f2(unsigned char flags) {
    vptr = g_vftable_222c0;
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
