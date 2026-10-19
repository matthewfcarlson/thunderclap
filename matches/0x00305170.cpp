#include "gen/physics.h"

typedef unsigned int u32_305170;
namespace physics {
} // namespace physics
struct Mgr_305170 { void FUN_00304bd0(u32_305170, u32_305170, u32_305170); };
void physics::CollisionObject::vfunc_6(int __p0, int __p1) { u32_305170 a = (u32_305170)__p0; u32_305170 b = (u32_305170)__p1;

    ((Mgr_305170*)this)->FUN_00304bd0(this->f_20, a, b);
}
