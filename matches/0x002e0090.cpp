extern "C" void _ReadWriteBarrier();
class Ref_2e0090 {
  public:
    virtual void f();
    virtual void Release();
};
extern int vtSkin, vtOpt, vtBase;
class PrimGroupSkinnedOptimized_2e0090 {
  public:
    void* vptr;
    char p4[0x3c];
    Ref_2e0090* m40;
    char p44[0x14];
    Ref_2e0090* m58;
    char p5c[4];
    Ref_2e0090* m60;
    Ref_2e0090* m64;
    void Cleanup();
    void BaseCleanup();
};
void PrimGroupSkinnedOptimized_2e0090::Cleanup() {
    *(void* volatile*)&vptr = &vtSkin;
    _ReadWriteBarrier();
    if (m60) {
        m60->Release();
        m60 = 0;
    }
    if (m64) {
        m64->Release();
        m64 = 0;
    }
    *(void* volatile*)&vptr = &vtOpt;
    _ReadWriteBarrier();
    if (m58) {
        m58->Release();
        m58 = 0;
    }
    *(void* volatile*)&vptr = &vtBase;
    _ReadWriteBarrier();
    if (m40) {
        m40->Release();
        m40 = 0;
    }
    BaseCleanup();
}
