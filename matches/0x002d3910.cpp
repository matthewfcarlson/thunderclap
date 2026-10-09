class ParticlePointGenerator {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual int vfunc_4();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
};
class Helper {
  public:
    int run(ParticlePointGenerator*);
};
extern "C" void* __cdecl allocThing(unsigned int);
int ParticlePointGenerator::vfunc_4() {
    void* p = allocThing(0x50);
    if (p)
        return ((Helper*)p)->run(this);
    return 0;
}