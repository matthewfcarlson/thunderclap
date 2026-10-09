class PhysicsJointMatrixModifier {
    char pad[0x18];
    void* p;

  public:
    int vfunc_5();
};
int PhysicsJointMatrixModifier::vfunc_5() {
    return *(int*)((char*)p + 8);
}