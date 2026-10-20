// Same code shape as 0x00091d50 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/physics.h"

int physics::CollisionRay::vfunc_3() {
    return (hulk_intptr)((physics::CollisionRay*)((char*)this + 0x68));
}
