#include "compat/ptr.h"
#include "gen/physics.h"
extern "C" char DAT_00431968[];
class PhysicsThing {
  public:
    int a[4];
    int b;
    unsigned char c;
};
struct WorldCollisionObject_nv_2fe1d0 {
    void BaseCtor();
};
PhysicsThing* __fastcall Target(PhysicsThing* self) {
    ((WorldCollisionObject_nv_2fe1d0*)(((physics::WorldCollisionObject*)(self))))->BaseCtor();
    *(hulk_intptr*)self = ((hulk_intptr)DAT_00431968);
    self->b = 0;
    self->c = 1;
    return self;
}