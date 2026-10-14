typedef unsigned int u32_18c8b0;
struct TrackFactoryTemplate {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual u32_18c8b0 f5();
};
struct Prop_18c8b0 {
    u32_18c8b0 init();
};
extern "C" void* __cdecl operator_new(unsigned int);
u32_18c8b0 TrackFactoryTemplate::f5() {
    Prop_18c8b0* p = (Prop_18c8b0*)operator_new(0x88);
    if (p)
        return p->init();
    return 0;
}