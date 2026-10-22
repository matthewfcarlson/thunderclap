extern "C" void _ReadWriteBarrier();
extern int vt1_2e06e0;
class Ref_2e06e0 {
  public:
    virtual void f0();
    virtual void Release();
};
class PrimGroupSkinnedOptimized_2e06e0 {
  public:
    void* vptr;
    char pad[0x64];
    Ref_2e06e0* child;
    ~PrimGroupSkinnedOptimized_2e06e0() throw();
};
class PrimGroupSkinnedPC_2e06e0 : public PrimGroupSkinnedOptimized_2e06e0 {
  public:
    ~PrimGroupSkinnedPC_2e06e0() throw();
};
PrimGroupSkinnedPC_2e06e0::~PrimGroupSkinnedPC_2e06e0() throw() {
    vptr = &vt1_2e06e0;
    _ReadWriteBarrier();
    if (child) {
        child->Release();
        child = 0;
    }
}
