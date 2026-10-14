typedef unsigned int u32_6f850;
struct TrackFactoryTemplate {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual u32_6f850 vfunc_5();
};
struct Grapple_6f850 {
    u32_6f850 ctor();
};
extern void* __cdecl Alloc(unsigned int);
u32_6f850 TrackFactoryTemplate::vfunc_5() {
    Grapple_6f850* p = (Grapple_6f850*)Alloc(0x2c);
    if (p)
        return p->ctor();
    return 0;
}
