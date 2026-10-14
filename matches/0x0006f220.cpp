typedef unsigned int u32_6f220;
extern void* __cdecl Alloc(unsigned int);
struct InitObj_6f220 {
    u32_6f220 Init();
};
class TrackFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual u32_6f220 vfunc_5();
};
u32_6f220 TrackFactoryTemplate::vfunc_5() {
    void* p = Alloc(0x60);
    if (p)
        return ((InitObj_6f220*)p)->Init();
    return 0;
}