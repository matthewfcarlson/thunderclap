class Ref { public: virtual void a(int); };
class CollisionSolverAgent { public: int vptr; int pad4; Ref* mPtr; CollisionSolverAgent* vfunc_2(unsigned char); };
extern void thunk(CollisionSolverAgent*);
CollisionSolverAgent* CollisionSolverAgent::vfunc_2(unsigned char flag) {
 vptr = 0x431700;
 if (mPtr) { mPtr->a(1); mPtr = 0; }
 vptr = 0x3f6098;
 if (flag & 1) thunk(this);
 return this;
}