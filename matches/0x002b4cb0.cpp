// Same code shape as 0x0013e710 (propagated; names are from that function)
struct TrackFactory { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); };
extern "C" void* __cdecl Allocate(unsigned int);
struct Built { void* init(); };
struct Factory : TrackFactory { void* vfunc_5(); };
void* Factory::vfunc_5() {
    void* p = Allocate(0x58);
    if (p) return ((Built*)p)->init();
    return 0;
}