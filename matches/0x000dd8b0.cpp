#include "compat/ptr.h"
#include "gen/global.h"
#include "decls/data/game/global.h"

struct Pair_dd8b0 {
    int a, b;
};

struct IDollyControllerState_dd8b0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual float vfunc_7(int);
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
};

hulk_freg ControllerState::vfunc_7(hulk_intptr index) {
    float* p = (*(float * *)&this->f_0c);
    return p[((Pair_dd8b0*)&DAT_004a0d6c)[index].a] - p[((Pair_dd8b0*)&DAT_004a0d6c)[index].b];
}
