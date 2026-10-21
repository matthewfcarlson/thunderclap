#include "compat/ptr.h"
extern "C" double sqrt(double);
class VecSource {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual float* Get();
};
class Obj_302480 {
  public:
    char pad[0x34];
    float radius;
};
hulk_freg dist(Obj_302480* a, Obj_302480* b) {
    float* p = ((VecSource*)a)->Get();
    float* q = ((VecSource*)b)->Get();
    hulk_freg x = q[0] - p[0];
    hulk_freg y = q[1] - p[1];
    hulk_freg z = q[2] - p[2];
    return (hulk_freg)sqrt(x * x + y * y + z * z) - (a->radius + b->radius);
}