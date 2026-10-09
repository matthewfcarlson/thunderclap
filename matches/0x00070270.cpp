// Same code shape as 0x0006fc10 (propagated; names are from that function)
typedef unsigned int u32;
extern "C" void* __cdecl Allocate(unsigned int);
class Created {
  public:
    u32 Initialize();
};
class TrackFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual u32 Create();
};
u32 TrackFactoryTemplate::Create() {
    Created* p = (Created*)Allocate(0xd0);
    if (p)
        return p->Initialize();
    return 0;
}