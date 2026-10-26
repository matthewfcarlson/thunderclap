#include "decls/data/game/global.h"
// data: one = DAT_003f32dc, zero = DAT_003f32e0

namespace physics {
class PhysicsJoint {
  public:
    virtual void vfunc_0();
};
class PhysicsJoint1D : public PhysicsJoint {
  public:
    char pad[0xf8];
    float x, y, z;
    virtual float vfunc_20(float* p);
};
} // namespace physics
struct ThisCall_0030b2c0 {
    float other(float);
};
float physics::PhysicsJoint1D::vfunc_20(float* p) {
    float d = z * p[2] + y * p[1] + x * p[0];
    if (d == DAT_003f32e0)
        return DAT_003f32dc;
    return ((ThisCall_0030b2c0*)(this))->other(d);
}