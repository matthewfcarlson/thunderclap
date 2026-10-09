typedef unsigned int u32;
struct Grapple {
    u32 BuildTrack();
};
struct TrackFactoryTemplate {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual u32 vfunc_5();
};
extern void* operator new(unsigned int);
u32 TrackFactoryTemplate::vfunc_5() {
    Grapple* p = (Grapple*)operator new(0x40);
    if (p)
        return p->BuildTrack();
    return 0;
}