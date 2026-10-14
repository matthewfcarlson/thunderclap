struct TrackFactory {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
extern "C" void* __cdecl Allocate(unsigned int);
struct Built_13e710 {
    void* init();
};
struct Factory_13e710 : TrackFactory {
    void* vfunc_5();
};
void* Factory_13e710::vfunc_5() {
    void* p = Allocate(0x58);
    if (p)
        return ((Built_13e710*)p)->init();
    return 0;
}