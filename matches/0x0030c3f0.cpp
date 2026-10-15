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
extern "C" float __stdcall other(float);
extern const float zero, one;
float physics::PhysicsJoint1D::vfunc_20(float* p) {
    float d = z * p[2] + y * p[1] + x * p[0];
    if (d == zero)
        return one;
    return other(d);
}