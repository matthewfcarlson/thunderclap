// Same code shape as 0x0006fa30 (propagated; names are from that function)
typedef unsigned int u32_14bfa0;
struct Grapple_14bfa0 {
    u32_14bfa0 BuildTrack();
};
struct TrackFactoryTemplate {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual u32_14bfa0 vfunc_5();
};
extern void* operator new(unsigned int);
u32_14bfa0 TrackFactoryTemplate::vfunc_5() {
    Grapple_14bfa0* p = (Grapple_14bfa0*)operator new(0x40);
    if (p)
        return p->BuildTrack();
    return 0;
}