// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 0/0)
// physics::CollisionWall::vfunc_13 @ 0x0030e870
#include "gen/physics.h"

namespace physics {
struct WallResult {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void *vfunc_4(unsigned int);
};
struct WallOwner { char pad[0x18]; WallResult *result; };
}
struct WallResponse { void FUN_0022c3b0(void *, void *); };
void physics::CollisionWall::vfunc_13() {
    this->f_19 = 1;
    WallResponse *response = (WallResponse *)(*(WallOwner * *)&this->f_10)->result->vfunc_4((*(unsigned int *)&this->f_08));
    response->FUN_0022c3b0((*(char (*)[4])&this->f_48), (*(char (*)[16])&this->f_38));
}
