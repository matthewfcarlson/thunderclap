#include "gen/physics.h"

class Helper_306fd0 {
  public:
    void c2(int, int);
    void c3(void*, void*);
};

void physics::CollisionRay::vfunc_11(void* __p0) { Helper_306fd0 * h = (Helper_306fd0 *)__p0;

    int a = vfunc_4();
    h->c2(vfunc_4(), a);
    h->c3((char*)this + 0x74, (char*)this + 0x74);
}
