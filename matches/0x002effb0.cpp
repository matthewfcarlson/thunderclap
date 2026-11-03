#include "compat/ptr.h"
#include "gen/physics.h"
#include "gen/owners.h"

class Other {
  public:
};
namespace physics {

} // namespace physics
void physics::CollisionSphere::vfunc_11(void* __p0) { Other * p = (Other *)__p0;

    ((owners::Mat_22c2b0 *)p)->FUN_0022c2b0((float *)(hulk_uintptr)(hulk_intptr)(vfunc_4()), (float *)(hulk_uintptr)(hulk_intptr)(vfunc_4()));
}
