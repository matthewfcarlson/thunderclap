typedef unsigned int uint;
struct TrackFactoryTemplate {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual int Create();
};
extern "C" void* __cdecl operator_new(unsigned int);
extern "C" int __fastcall Construct(void*);
int TrackFactoryTemplate::Create() {
    void* p = operator_new(0x34);
    if (p)
        return Construct(p);
    return 0;
}