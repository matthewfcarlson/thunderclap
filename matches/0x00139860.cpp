typedef unsigned int u32;
struct Init {
    u32 run();
};
extern void* alloc(unsigned int);
struct TrackFactoryTemplate {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual u32 create();
};
u32 TrackFactoryTemplate::create() {
    void* p = alloc(0x4c);
    if (p)
        return ((Init*)p)->run();
    return 0;
}