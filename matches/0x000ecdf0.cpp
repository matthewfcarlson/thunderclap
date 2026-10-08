struct Vec3 { int pad; float x; float y; };
struct X { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void h(); virtual void i(); virtual void j(); virtual void k(); virtual void l(); virtual void m(); virtual void n(); virtual void o(); virtual void p(Vec3*, void*); };
struct TextWindow { char pad[20]; X* obj; float vfunc_8(); };
float TextWindow::vfunc_8() { Vec3 v; obj->p(&v, this); return v.x * 1.05f; }
