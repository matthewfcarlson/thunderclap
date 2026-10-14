// Same code shape as 0x0006fa30 (propagated; names are from that function)
typedef unsigned int u32_13e560;
struct Grapple_13e560 {
    u32_13e560 BuildTrack();
};
struct TrackFactoryTemplate {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual u32_13e560 vfunc_5();
};
extern void* operator new(unsigned int);
u32_13e560 TrackFactoryTemplate::vfunc_5() {
    Grapple_13e560* p = (Grapple_13e560*)operator new(0x40);
    if (p)
        return p->BuildTrack();
    return 0;
}