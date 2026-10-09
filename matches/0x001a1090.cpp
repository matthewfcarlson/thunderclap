typedef unsigned int u32;
class TrackFactory { public: virtual void a(); virtual void b(); };
class Entity { public: virtual void c(); virtual void d(); virtual void e(); };
class LoadObject { public: virtual void f(); virtual void g(); };
class IRefCount { public: virtual void h(); };
extern void* __cdecl operator_new(unsigned int);
class Thing { public: u32 init(); };
class Factory : public TrackFactory, public Entity, public LoadObject, public IRefCount { public: virtual u32 vfunc_5(); };
u32 Factory::vfunc_5() { Thing* p=(Thing*)operator_new(0xc0); if(p) return p->init(); return 0; }