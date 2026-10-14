namespace physics {
struct Sub_30d470 {
    char pad[0x1c];
    Sub_30d470() throw();
};
struct Vec_30d470 {
    float x, y, z;
    Vec_30d470() throw() {}
    Vec_30d470(float a, float b, float c) throw() : x(a), y(b), z(c) {}
};
class PhysicsJoint {
  public:
    virtual ~PhysicsJoint() throw();
    char pad[0x1c];
    Vec_30d470 v;
    char pad2[0x48 - 0x2c];
    Sub_30d470 s1;
    Sub_30d470 s2;
    PhysicsJoint() throw() : v(0.0f, 0.0f, 0.0f) {}
};
class PhysicsJoint3D : public PhysicsJoint {
  public:
    virtual ~PhysicsJoint3D() throw();
    PhysicsJoint3D() throw();
};
PhysicsJoint3D::PhysicsJoint3D() throw() {}
} // namespace physics
