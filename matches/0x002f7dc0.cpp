#include "compat/ptr.h"
#include "gen/physics.h"

class Obj_2f7dc0 {
  public:
    char pad[0x6c];
    int state;
    void helper(int);
};
class Ref_2f7dc0 {
  public:
    char pad[0x20];
    int state;
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(void*, int, void*, int, int, int, int);
};

unsigned int physics::CollisionSolverAgent::vfunc_6(hulk_uintptr __p0, unsigned int __p1, hulk_uintptr __p2, unsigned int __p3, unsigned int __p4, unsigned int __p5, unsigned int __p6, hulk_uintptr __p7, hulk_uintptr __p8) { void * a = (void *)__p0; int b = (int)__p1; void * c = (void *)__p2; int d = (int)__p3; int e = (int)__p4; int f = (int)__p5; int g = (int)__p6; int * p = (int *)__p7; int * q = (int *)__p8;

    if (*p && !((Ref_2f7dc0*)*(hulk_intptr*)p)->state && !((Obj_2f7dc0*)a)->state)
        ((Obj_2f7dc0*)a)->helper(1);
    if (*q && !((Ref_2f7dc0*)*(hulk_intptr*)q)->state && !((Obj_2f7dc0*)c)->state)
        ((Obj_2f7dc0*)c)->helper(1);
    if ((*(void * *)&this->f_08))
        ((Ref_2f7dc0*)(*(void * *)&this->f_08))->f4(a, b, c, d, e, f, g);
    return (unsigned int)(0);
}
