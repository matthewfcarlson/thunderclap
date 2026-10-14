typedef unsigned int u32_1a1090;
class TrackFactory {
  public:
    virtual void a();
    virtual void b();
};
class Entity {
  public:
    virtual void c();
    virtual void d();
    virtual void e();
};
class LoadObject {
  public:
    virtual void f();
    virtual void g();
};
class IRefCount {
  public:
    virtual void h();
};
extern void* __cdecl operator_new(unsigned int);
class Thing_1a1090 {
  public:
    u32_1a1090 init();
};
class Factory_1a1090 : public TrackFactory, public Entity, public LoadObject, public IRefCount {
  public:
    virtual u32_1a1090 vfunc_5();
};
u32_1a1090 Factory_1a1090::vfunc_5() {
    Thing_1a1090* p = (Thing_1a1090*)operator_new(0xc0);
    if (p)
        return p->init();
    return 0;
}