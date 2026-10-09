class Base {
  public:
    char pad[0x18];
    Base();
};
class PhysicsJointMatrixModifier : public Base {
  public:
    void* member;
    PhysicsJointMatrixModifier(void*);
};
PhysicsJointMatrixModifier::PhysicsJointMatrixModifier(void* arg) {
    member = arg;
    *(void**)this = (void*)0x431840;
}