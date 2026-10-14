// Same code shape as 0x0006f220 (propagated; names are from that function)
typedef unsigned int u32_77be0;
extern void* __cdecl Alloc(unsigned int);
struct InitObj_77be0 {
    u32_77be0 Init();
};
class TrackFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual u32_77be0 vfunc_5();
};
u32_77be0 TrackFactoryTemplate::vfunc_5() {
    void* p = Alloc(0x60);
    if (p)
        return ((InitObj_77be0*)p)->Init();
    return 0;
}