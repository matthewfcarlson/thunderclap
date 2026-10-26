#include "decls/data/engine/pure3d/prop.h"
// data: globalManager = DAT_0052c2ac

class Other_2a36d0;
class DrawableContainer {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void vfunc_6(void*, int);
};
class ParticleSystem : public DrawableContainer {
  public:
    char pad[0xa0];
    Other_2a36d0* emitter;
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    void vfunc_6(void*, int);
};
class Other_2a36d0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g(void*, int);
    virtual void h();
};
class Manager_2a36d0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q(int);
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u();
    virtual void v();
    virtual void w();
    virtual void x(int, void*);
};
void ParticleSystem::vfunc_6(void* a, int b) {
    if (emitter)
        emitter->g(a, b);
    if ((char)b == 1) {
        (*(*(Manager_2a36d0***)&DAT_0052c2ac))->x(0, (char*)this + 0x64);
        emitter->h();
    }
    DrawableContainer::vfunc_6(a, b);
    if ((char)b == 1)
        (*(*(Manager_2a36d0***)&DAT_0052c2ac))->q(0);
}
