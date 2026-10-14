// Same code shape as 0x0006f3d0 (propagated; names are from that function)
typedef unsigned int u32_18ca60;
struct CGrabTrack {
    u32_18ca60 init();
};
struct TrackFactoryTemplate {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual u32_18ca60 vfunc_5();
};
extern "C" void* __cdecl operator_new(unsigned int);
u32_18ca60 TrackFactoryTemplate::vfunc_5() {
    CGrabTrack* p = (CGrabTrack*)operator_new(0x50);
    if (p)
        return p->init();
    return 0;
}