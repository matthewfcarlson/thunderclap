// Same code shape as 0x0006fac0 (propagated; names are from that function)
class Track {
  public:
    int method();
};
class TrackFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual int vfunc_5();
};
extern void* __cdecl operator_new(unsigned int);
int TrackFactoryTemplate::vfunc_5() {
    Track* p = (Track*)operator_new(0x38);
    if (p)
        return p->method();
    return 0;
}