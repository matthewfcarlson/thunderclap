#include "gen/physics.h"

class Other {
  public:
    void Use(int a, int b);
};
namespace physics {

} // namespace physics
void physics::CollisionSphere::vfunc_11(void* __p0) { Other * p = (Other *)__p0;

    p->Use(vfunc_4(), vfunc_4());
}
