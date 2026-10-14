// Same code shape as 0x0006fa30 (propagated; names are from that function)
typedef unsigned int u32_146890;
struct Grapple_146890 {
    u32_146890 BuildTrack();
};
struct TrackFactoryTemplate {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual u32_146890 vfunc_5();
};
extern void* operator new(unsigned int);
u32_146890 TrackFactoryTemplate::vfunc_5() {
    Grapple_146890* p = (Grapple_146890*)operator new(0x40);
    if (p)
        return p->BuildTrack();
    return 0;
}