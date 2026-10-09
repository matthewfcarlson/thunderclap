// Same code shape as 0x0006f850 (propagated; names are from that function)
typedef unsigned int u32;
struct TrackFactoryTemplate { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual u32 vfunc_5(); };
struct Grapple { u32 ctor(); };
extern void* __cdecl Alloc(unsigned int);
u32 TrackFactoryTemplate::vfunc_5() { Grapple* p = (Grapple*)Alloc(0x2c); if (p) return p->ctor(); return 0; }
