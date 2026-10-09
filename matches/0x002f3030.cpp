typedef unsigned char u8;
extern int vtable;
struct Part { void init(); };
namespace physics { struct CollisionCylinder {
 virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void h(); virtual void i(); virtual void j(); virtual void k(); virtual void l(); virtual void m(); virtual void n(); virtual void o();
 char pad[0x64-4];
 CollisionCylinder* vfunc_2(u8);
 void base();
}; }
void cleanup(physics::CollisionCylinder*);
physics::CollisionCylinder* physics::CollisionCylinder::vfunc_2(u8 flag) {
 *(int*)this = (int)&vtable;
 ((Part*)((char*)this+0x64))->init();
 ((Part*)((char*)this+0x38))->init();
 base();
 if(flag&1) cleanup(this);
 return this;
}