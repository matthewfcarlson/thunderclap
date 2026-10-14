typedef unsigned int u32_139860;
struct Init_139860 {
    u32_139860 run();
};
extern void* alloc(unsigned int);
struct TrackFactoryTemplate {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual u32_139860 create();
};
u32_139860 TrackFactoryTemplate::create() {
    void* p = alloc(0x4c);
    if (p)
        return ((Init_139860*)p)->run();
    return 0;
}