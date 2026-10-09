class PhysicsObject {
    char pad[0x1c4];

  public:
    void vfunc_10();
};
void PhysicsObject::vfunc_10() {
    pad[0x1c4] = 1;
}