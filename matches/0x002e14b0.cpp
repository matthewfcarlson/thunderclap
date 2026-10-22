extern "C" void _ReadWriteBarrier();
extern int vt1_2e14b0, vt2;
extern void Free(void*);
class Ref_2e14b0 {
  public:
    virtual void f0();
    virtual void Release();
};
class PrimGroup_2e14b0 {
  public:
    void* vptr;
    void Fini();
};
class PrimGroupOptimized_2e14b0 : public PrimGroup_2e14b0 {
  public:
    char p[0x3c];
    Ref_2e14b0* a40;
    char q[0x14];
    Ref_2e14b0* a58;
    PrimGroupOptimized_2e14b0* vfunc2(unsigned char f);
};
PrimGroupOptimized_2e14b0* PrimGroupOptimized_2e14b0::vfunc2(unsigned char f) {
    vptr = &vt1_2e14b0;
    _ReadWriteBarrier();
    if (a58) {
        a58->Release();
        a58 = 0;
    }
    vptr = &vt2;
    _ReadWriteBarrier();
    if (a40) {
        a40->Release();
        a40 = 0;
    }
    Fini();
    if (f & 1)
        Free(this);
    return this;
}
