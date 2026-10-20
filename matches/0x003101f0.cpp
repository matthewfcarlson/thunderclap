#include "compat/ptr.h"
#include "gen/physics.h"
extern "C" char DAT_0043217c[];
class ArticulatedPhysicsObject_3101f0 {
  public:
    ArticulatedPhysicsObject_3101f0* Init();
};
struct ArticulatedPhysicsObject_nv_3101f0 {
    void InitBase();
};
ArticulatedPhysicsObject_3101f0* ArticulatedPhysicsObject_3101f0::Init() {
    ((ArticulatedPhysicsObject_nv_3101f0*)(((physics::ArticulatedPhysicsObject*)(this))))->InitBase();
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_0043217c);
    *(unsigned int*)((char*)this + 0x1fc) = 0;
    *(unsigned int*)((char*)this + 0x24) = 1;
    return this;
}