void* __cdecl Allocate(unsigned int);
struct Grapple { int Build(); };
class TrackFactoryTemplate { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual int vfunc_5(); };
int TrackFactoryTemplate::vfunc_5() {
    Grapple* p = (Grapple*)Allocate(0x80);
    if (p) return p->Build();
    return 0;
}