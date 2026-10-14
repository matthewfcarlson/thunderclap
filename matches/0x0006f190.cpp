void* __cdecl Allocate(unsigned int);
class Obj_6f190 {
  public:
    void* Initialize();
};
class TrackFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* vfunc_5();
};
void* TrackFactoryTemplate::vfunc_5() {
    Obj_6f190* p = (Obj_6f190*)Allocate(0x120);
    if (p)
        return p->Initialize();
    return 0;
}