#include "compat/ptr.h"
#include "gen/physics.h"
#include "gen/owners.h"

class Helper_306fd0 {
  public:
};

void physics::CollisionRay::vfunc_11(void* __p0) { Helper_306fd0 * h = (Helper_306fd0 *)__p0;

    hulk_intptr a = vfunc_4();
    ((owners::Mat_22c2b0 *)h)->FUN_0022c2b0((float *)(hulk_uintptr)(hulk_intptr)(vfunc_4()), (float *)(hulk_uintptr)(hulk_intptr)a);
    ((owners::M_22c3b0 *)h)->FUN_0022c3b0((float *)((char*)this + 0x74), (float *)((char*)this + 0x74));
}
