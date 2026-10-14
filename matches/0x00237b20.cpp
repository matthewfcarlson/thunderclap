// Same code shape as 0x0006f850 (propagated; names are from that function)
typedef unsigned int u32_237b20;
struct TrackFactoryTemplate {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual u32_237b20 vfunc_5();
};
struct Grapple_237b20 {
    u32_237b20 ctor();
};
extern void* __cdecl Alloc(unsigned int);
u32_237b20 TrackFactoryTemplate::vfunc_5() {
    Grapple_237b20* p = (Grapple_237b20*)Alloc(0x2c);
    if (p)
        return p->ctor();
    return 0;
}
