// Same code shape as 0x0006f220 (propagated; names are from that function)
typedef unsigned int u32_123180;
extern void* __cdecl Alloc(unsigned int);
struct InitObj_123180 {
    u32_123180 Init();
};
class TrackFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual u32_123180 vfunc_5();
};
u32_123180 TrackFactoryTemplate::vfunc_5() {
    void* p = Alloc(0x60);
    if (p)
        return ((InitObj_123180*)p)->Init();
    return 0;
}