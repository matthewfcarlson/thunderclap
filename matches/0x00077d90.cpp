extern "C" char DAT_003fba00[];
struct CScrubberTrack {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    void Ctor();
};
extern void* __cdecl operator_new(unsigned int);
class TrackFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual CScrubberTrack* vfunc_5();
};
CScrubberTrack* TrackFactoryTemplate::vfunc_5() {
    CScrubberTrack* p = (CScrubberTrack*)operator_new(0x0c);
    if (p) {
        p->Ctor();
        *(unsigned int*)p = ((int)DAT_003fba00);
        return p;
    }
    return 0;
}