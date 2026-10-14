typedef unsigned int u32_6fc10;
extern "C" void* __cdecl Allocate(unsigned int);
class Created_6fc10 {
  public:
    u32_6fc10 Initialize();
};
class TrackFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual u32_6fc10 Create();
};
u32_6fc10 TrackFactoryTemplate::Create() {
    Created_6fc10* p = (Created_6fc10*)Allocate(0xd0);
    if (p)
        return p->Initialize();
    return 0;
}