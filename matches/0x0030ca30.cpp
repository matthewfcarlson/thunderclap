namespace physics {
struct Sub_30ca30 {
    char pad[0x1c];
    Sub_30ca30() throw();
};
struct Vec_30ca30 {
    float x, y, z;
    Vec_30ca30() throw() {}
    Vec_30ca30(float a, float b, float c) throw() : x(a), y(b), z(c) {}
};
class PhysicsJoint {
  public:
    virtual ~PhysicsJoint() throw();
    char pad[0x1c];
    Vec_30ca30 v;
    char pad2[0x48 - 0x2c];
    Sub_30ca30 s1;
    Sub_30ca30 s2;
    PhysicsJoint() throw();
};
PhysicsJoint::PhysicsJoint() throw() : v(0.0f, 0.0f, 0.0f) {}
} // namespace physics
