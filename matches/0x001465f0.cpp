// Same code shape as 0x0013e710 (propagated; names are from that function)
struct TrackFactory {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
extern "C" void* __cdecl Allocate(unsigned int);
struct Built_1465f0 {
    void* init();
};
struct Factory_1465f0 : TrackFactory {
    void* vfunc_5();
};
void* Factory_1465f0::vfunc_5() {
    void* p = Allocate(0x58);
    if (p)
        return ((Built_1465f0*)p)->init();
    return 0;
}