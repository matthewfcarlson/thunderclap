typedef unsigned int u32;
struct Obj { virtual void a(); virtual void b(); virtual u32 c(); virtual void d(); virtual u32 e(); virtual void f(); virtual void g(); virtual void h(); virtual void i(); virtual void j(); virtual void k(); virtual void l(); virtual void m(); virtual void n(); virtual void o(); };
namespace physics { class CollisionCylinder : public Obj { public: char pad[0x40]; float x; void vfunc_11(void*); }; }
struct Helper { void first(void*,void*); void second(u32,u32); };
void physics::CollisionCylinder::vfunc_11(void* p) { Helper* h=(Helper*)p; h->first(&x,&x); u32 a=e(); h->second(e(),a); }
