extern void* g_vftable[];
extern "C" void _ReadWriteBarrier();
class SimpleFrameController_2a80c0 {
  public:
    SimpleFrameController_2a80c0();
    virtual void f0();
    char pad[0x3c];
};
class CompDrawVisibilityAnimationController_2a80c0 : public SimpleFrameController_2a80c0 {
  public:
    CompDrawVisibilityAnimationController_2a80c0();
    virtual void f0();
    int m40;
    int m44;
    int m48;
    int pad4c;
    int m50;
    int m54;
};
CompDrawVisibilityAnimationController_2a80c0::CompDrawVisibilityAnimationController_2a80c0() {
    m40 = 0;
    *(void**)this = g_vftable;
    _ReadWriteBarrier();
    m44 = 0;
    m48 = 0;
    m50 = 0;
    m54 = 0;
}
