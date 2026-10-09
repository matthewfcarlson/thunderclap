void* __cdecl Allocate(unsigned int);
class Obj { public: void* Initialize(); };
class TrackFactoryTemplate { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void* vfunc_5(); };
void* TrackFactoryTemplate::vfunc_5() { Obj* p = (Obj*)Allocate(0x120); if (p) return p->Initialize(); return 0; }