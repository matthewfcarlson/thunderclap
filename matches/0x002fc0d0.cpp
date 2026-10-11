extern "C" char DAT_00431840[];
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
    *(void**)this = (void*)((int)DAT_00431840);
}