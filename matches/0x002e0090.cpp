extern "C" void _ReadWriteBarrier();
class Ref {
  public:
    virtual void f();
    virtual void Release();
};
extern int vtSkin, vtOpt, vtBase;
class Obj {
  public:
    void* vptr;
    char p4[0x3c];
    Ref* m40;
    char p44[0x14];
    Ref* m58;
    char p5c[4];
    Ref* m60;
    Ref* m64;
    void Cleanup();
    void BaseCleanup();
};
void Obj::Cleanup() {
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
