namespace physics {
struct Sub_30d3f0 {
    char pad[0x1c];
    Sub_30d3f0() throw();
};
struct Vec_30d3f0 {
    float x, y, z;
    Vec_30d3f0() throw() {}
    Vec_30d3f0(float a, float b, float c) throw() : x(a), y(b), z(c) {}
};
class PhysicsJoint {
  public:
    virtual ~PhysicsJoint() throw();
    char pad[0x1c];
    Vec_30d3f0 v;
    char pad2[0x48 - 0x2c];
    Sub_30d3f0 s1;
    Sub_30d3f0 s2;
    PhysicsJoint() throw() : v(0.0f, 0.0f, 0.0f) {}
};
class PhysicsJoint1D : public PhysicsJoint {
  public:
    virtual ~PhysicsJoint1D() throw();
    PhysicsJoint1D() throw();
};
PhysicsJoint1D::PhysicsJoint1D() throw() {}
} // namespace physics
