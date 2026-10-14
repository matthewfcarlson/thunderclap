// Same code shape as 0x0006f850 (propagated; names are from that function)
typedef unsigned int u32_122d30;
struct TrackFactoryTemplate {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual u32_122d30 vfunc_5();
};
struct Grapple_122d30 {
    u32_122d30 ctor();
};
extern void* __cdecl Alloc(unsigned int);
u32_122d30 TrackFactoryTemplate::vfunc_5() {
    Grapple_122d30* p = (Grapple_122d30*)Alloc(0x2c);
    if (p)
        return p->ctor();
    return 0;
}
