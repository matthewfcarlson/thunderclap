#include "gen/pure3d.h"

struct Inner_2d3e80 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h(int, int);
};

void pure3d::ParticleEmitter::vfunc_17(int a, int b) {
    if ((*(Inner_2d3e80 * *)&this->f_88))
        (*(Inner_2d3e80 * *)&this->f_88)->h(a, b);
}
