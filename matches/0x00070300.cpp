void* __cdecl FUN_0008d690(unsigned int);
struct Thing_70300 {
    unsigned int go();
};
class TrackFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual unsigned int vfunc_5();
};
unsigned int TrackFactoryTemplate::vfunc_5() {
    void* p = FUN_0008d690(0x44);
    if (p)
        return ((Thing_70300*)p)->go();
    return 0;
}