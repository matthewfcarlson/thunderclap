typedef unsigned int size_t;
void* Alloc(unsigned int);
class Obj_1a1240 {
  public:
    void* Init();
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
    Obj_1a1240* p = (Obj_1a1240*)Alloc(0xb0);
    if (p)
        return p->Init();
    return 0;
}