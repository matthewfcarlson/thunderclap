// Same code shape as 0x0006fc10 (propagated; names are from that function)
typedef unsigned int u32_70270;
extern "C" void* __cdecl Allocate(unsigned int);
class Created_70270 {
  public:
    u32_70270 Initialize();
};
class TrackFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual u32_70270 Create();
};
u32_70270 TrackFactoryTemplate::Create() {
    Created_70270* p = (Created_70270*)Allocate(0xd0);
    if (p)
        return p->Initialize();
    return 0;
}