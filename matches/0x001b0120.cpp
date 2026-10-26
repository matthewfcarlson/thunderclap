#include "compat/ptr.h"
#include "gen/global.h"

class AICollisionSolverAgent_1b0120 {
  public:
    virtual void a();
    virtual void b();
    virtual void x();
    virtual void y();
    virtual void c(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                   unsigned int);
};
void AICollisionSolverAgent_1b0120::a() {}
void AICollisionSolverAgent_1b0120::b() {}
void AICollisionSolverAgent_1b0120::x() {}
void AICollisionSolverAgent_1b0120::y() {}
void AICollisionSolverAgent_1b0120::c(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                             unsigned int, unsigned int) {}

unsigned int AICollisionSolverAgent::vfunc_6(hulk_uintptr p1, unsigned int p2, hulk_uintptr p3, unsigned int p4, unsigned int p5, unsigned int p6, unsigned int p7, hulk_uintptr p8, hulk_uintptr p9) {
    if ((*(AICollisionSolverAgent_1b0120 * *)&this->f_08))
        (*(AICollisionSolverAgent_1b0120 * *)&this->f_08)->c(p1, p2, p3, p4, p5, p6, p7);
    return 0;
}
