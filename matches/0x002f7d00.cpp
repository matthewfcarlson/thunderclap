class Ref_2f7d00 {
  public:
    virtual void x();
    virtual void y(int, int);
};

class CollisionSolverAgent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(int, int);
    int pad;
    Ref_2f7d00* ref;
};

void CollisionSolverAgent::vfunc_3(int a, int b) {
    if (ref)
        ref->y(a, b);
}
