class CollisionSolverAgent {
  public:
    virtual void a();
    virtual void b();
    virtual void x();
    virtual void y();
    virtual void c(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                   unsigned int);
};
class AICollisionSolverAgent {
  public:
    char pad[8];
    CollisionSolverAgent* agent;
    unsigned int vfunc_6(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                         unsigned int, unsigned int, unsigned int);
};
void CollisionSolverAgent::a() {}
void CollisionSolverAgent::b() {}
void CollisionSolverAgent::x() {}
void CollisionSolverAgent::y() {}
void CollisionSolverAgent::c(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                             unsigned int, unsigned int) {}
unsigned int AICollisionSolverAgent::vfunc_6(unsigned int p1, unsigned int p2, unsigned int p3,
                                             unsigned int p4, unsigned int p5, unsigned int p6,
                                             unsigned int p7, unsigned int p8, unsigned int p9) {
    if (agent)
        agent->c(p1, p2, p3, p4, p5, p6, p7);
    return 0;
}