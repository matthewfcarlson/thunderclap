typedef unsigned int u32_1a1120;
struct Obj_1a1120 {
    u32_1a1120 Init();
};
extern void* __cdecl Alloc(unsigned int);
struct TrackFactoryTemplate {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual u32_1a1120 f();
};
u32_1a1120 TrackFactoryTemplate::f() {
    Obj_1a1120* p = (Obj_1a1120*)Alloc(0x138);
    if (p)
        return p->Init();
    return 0;
}