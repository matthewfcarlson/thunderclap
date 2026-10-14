namespace physics {
struct Sub_30d370 {
    char pad[0x1c];
    Sub_30d370() throw();
};
struct Vec_30d370 {
    float x, y, z;
    Vec_30d370() throw() {}
    Vec_30d370(float a, float b, float c) throw() : x(a), y(b), z(c) {}
};
class PhysicsJoint {
  public:
    virtual ~PhysicsJoint() throw();
    char pad[0x1c];
    Vec_30d370 v;
    char pad2[0x48 - 0x2c];
    Sub_30d370 s1;
    Sub_30d370 s2;
    PhysicsJoint() throw() : v(0.0f, 0.0f, 0.0f) {}
};
class PhysicsJoint0D : public PhysicsJoint {
  public:
    virtual ~PhysicsJoint0D() throw();
    PhysicsJoint0D() throw();
};
PhysicsJoint0D::PhysicsJoint0D() throw() {}
} // namespace physics
