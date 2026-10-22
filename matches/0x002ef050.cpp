struct CollisionDetector_2ef050 {
    void f();
};
struct ImpulseBasedCollisionSolver_2ef050 {
    void f();
};
struct S3_2ef050 {
    void f();
};
struct C_2ef050 {
    char pad[0x70];
    void f();
    C_2ef050* target();
};
C_2ef050* C_2ef050::target() {
    f();
    ((CollisionDetector_2ef050*)(pad + 0x70))->f();
    ((ImpulseBasedCollisionSolver_2ef050*)(pad + 0xb0))->f();
    ((S3_2ef050*)(pad + 0x1b0))->f();
    pad[0x6c] = 0;
    return this;
}