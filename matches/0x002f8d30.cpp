extern "C" char DAT_003f6098[];
extern "C" char DAT_00431700[];
class Ref_2f8d30 {
  public:
    virtual void a(int);
};
class CollisionSolverAgent {
  public:
    int vptr;
    int pad4;
    Ref_2f8d30* mPtr;
    CollisionSolverAgent* vfunc_2(unsigned char);
};
extern void thunk(CollisionSolverAgent*);
CollisionSolverAgent* CollisionSolverAgent::vfunc_2(unsigned char flag) {
    vptr = ((int)DAT_00431700);
    if (mPtr) {
        mPtr->a(1);
        mPtr = 0;
    }
    vptr = ((int)DAT_003f6098);
    if (flag & 1)
        thunk(this);
    return this;
}