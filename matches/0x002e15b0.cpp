extern "C" void _ReadWriteBarrier();
extern void* g_vt_2e15b0[];
void operator delete(void*);
class Ref_2e15b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class PrimGroupSkinnedOptimized_2e15b0 {
  public:
    void* vptr;
    void Fin();
};
class PrimGroupSkinnedPC_2e15b0 : public PrimGroupSkinnedOptimized_2e15b0 {
  public:
    char pad[104 - 4];
    Ref_2e15b0* m;
    PrimGroupSkinnedPC_2e15b0* f2(unsigned char flags);
};
PrimGroupSkinnedPC_2e15b0* PrimGroupSkinnedPC_2e15b0::f2(unsigned char flags) {
    vptr = g_vt_2e15b0;
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
