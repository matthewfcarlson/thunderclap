typedef unsigned int u32_6fa30;
struct Grapple_6fa30 {
    u32_6fa30 BuildTrack();
};
struct TrackFactoryTemplate {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual u32_6fa30 vfunc_5();
};
extern void* operator new(unsigned int);
u32_6fa30 TrackFactoryTemplate::vfunc_5() {
    Grapple_6fa30* p = (Grapple_6fa30*)operator new(0x40);
    if (p)
        return p->BuildTrack();
    return 0;
}