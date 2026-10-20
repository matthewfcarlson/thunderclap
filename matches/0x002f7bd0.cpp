#include "compat/ptr.h"
#include "gen/physics.h"

class C_2f7bd0 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual bool first(int, int, int, int, int, int);
    virtual void a19();
    virtual bool second(int, int, int, int, int);
};

bool physics::ImpulseBasedCollisionSolver::vfunc_2(void* __p0, int a, int b, int c, int d, int e) { C_2f7bd0 * o = (C_2f7bd0 *)__p0;

    bool r = true;
    if (o) {
        if (!o->first(b, (hulk_intptr)((char*)this + 0x50), c, a, d, e)) {
            o->second(b, c, a, d, e);
            r = false;
        }
    }
    return r;
}
