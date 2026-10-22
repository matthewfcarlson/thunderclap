struct A_2ef080 {
    void one();
};
struct ImpulseBasedCollisionSolver_2ef080 {
    void two();
};
struct CollisionDetector_2ef080 {
    void three();
};
struct Obj_2ef080 {
    char p70[0x70];
    CollisionDetector_2ef080 c;
    char p_after_c[0x3f];
    ImpulseBasedCollisionSolver_2ef080 b;
    char p_after_b[0xff];
    A_2ef080 a;
    void target();
    void finish();
};
void Obj_2ef080::target() {
    a.one();
    b.two();
    c.three();
    finish();
}
