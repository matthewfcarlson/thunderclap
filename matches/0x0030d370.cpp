namespace physics {
struct Sub {
    char pad[0x1c];
    Sub() throw();
};
struct Vec {
    float x, y, z;
    Vec() throw() {}
    Vec(float a, float b, float c) throw() : x(a), y(b), z(c) {}
};
class PhysicsJoint {
  public:
    virtual ~PhysicsJoint() throw();
    char pad[0x1c];
    Vec v;
    char pad2[0x48 - 0x2c];
    Sub s1;
    Sub s2;
    PhysicsJoint() throw() : v(0.0f, 0.0f, 0.0f) {}
};
class PhysicsJoint0D : public PhysicsJoint {
  public:
    virtual ~PhysicsJoint0D() throw();
    PhysicsJoint0D() throw();
};
PhysicsJoint0D::PhysicsJoint0D() throw() {}
} // namespace physics
