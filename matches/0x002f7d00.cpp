#include "gen/physics.h"

class Ref_2f7d00 {
  public:
    virtual void x();
    virtual void y(int, int);
};

void physics::CollisionSolverAgent::vfunc_3(int a, int b) {
    if ((*(Ref_2f7d00 * *)&this->f_08))
        (*(Ref_2f7d00 * *)&this->f_08)->y(a, b);
}
