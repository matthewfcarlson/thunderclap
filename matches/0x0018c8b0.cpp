typedef unsigned int u32;
struct TrackFactoryTemplate {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual u32 f5();
};
struct Prop {
    u32 init();
};
extern "C" void* __cdecl operator_new(unsigned int);
u32 TrackFactoryTemplate::f5() {
    Prop* p = (Prop*)operator_new(0x88);
    if (p)
        return p->init();
    return 0;
}