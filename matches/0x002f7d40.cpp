#include "gen/physics.h"

typedef unsigned int u32_2f7d40;
class Ref_2f7d40 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d(void*, void*);
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual int check(u32_2f7d40);
};
class Wrap_2f7d40 {
  public:
    char pad[0x18];
    Ref_2f7d40* obj;
};
struct Arg_2f7d40 {
    char x[8];
    Wrap_2f7d40* first;
    Wrap_2f7d40* second;
    u32_2f7d40 a;
    u32_2f7d40 b;
};

int physics::CollisionSolverAgent::vfunc_5(void* __p0, void* __p1) { void * p = (void *)__p0; void * secondArg = (void *)__p1;

    Arg_2f7d40* q = (Arg_2f7d40*)p;
    int r = 0;
    if (!q->first->obj->check(q->a) && !q->second->obj->check(q->b)) {
        if (!(*(Ref_2f7d40 * *)&this->f_08))
            r = 1;
    }
    if ((*(Ref_2f7d40 * *)&this->f_08))
        (*(Ref_2f7d40 * *)&this->f_08)->d(p, secondArg);
    return r;
}
