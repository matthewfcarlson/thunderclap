extern "C" char DAT_00431700[];
class CollisionSolverAgent {
  public:
    void* vptr;
    int a;
    int b;
    CollisionSolverAgent();
};
CollisionSolverAgent::CollisionSolverAgent() {
    a = 0;
    vptr = (void*)((int)DAT_00431700);
    b = 0;
}