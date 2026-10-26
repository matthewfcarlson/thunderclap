// Same code shape as 0x00091d50 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/physics.h"

hulk_intptr physics::CollisionRay::vfunc_4() {
    return (hulk_intptr)((physics::CollisionRay*)((char*)this + 0x68));
}
