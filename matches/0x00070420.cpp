typedef unsigned int uint;
extern void* __cdecl Allocate(unsigned int);
struct Track {
    void* Init();
};
class TrackFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* Create();
};
void* TrackFactoryTemplate::Create() {
    void* p = Allocate(0x48);
    if (p)
        return ((Track*)p)->Init();
    return 0;
}