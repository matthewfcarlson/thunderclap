#include "gen/physics.h"

#include "compat/ptr.h"
extern "C" char DAT_00431968[];
class Ref_2fe1f0 {
  public:
    virtual void f0();
    virtual void f1();
};
class Entity_2fe1f0 {
  public:
    void finish();
};
struct WorldCollisionObject_nv_2fe1f0 {
    void finish();
};

void physics::WorldCollisionObject::FUN_002fe1f0() {
    *(void**)this = (void*)((hulk_intptr)DAT_00431968);
    if ((*(Ref_2fe1f0 * *)&this->f_10))
        (*(Ref_2fe1f0 * *)&this->f_10)->f1();
    ((WorldCollisionObject_nv_2fe1f0*)this)->finish();
}
