class PhysicsJoint1D {
  public:
    char pad[0xfc];
    float a, b, c;
    char pad2[4];
    float value;
    void vfunc_24(float*);
};
void PhysicsJoint1D::vfunc_24(float* p) {
    value = a * p[0] + b * p[1] + c * p[2] + value;
}