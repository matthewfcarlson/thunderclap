// Same code shape as 0x00293970 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/pure3d.h"

typedef unsigned int U_2a7700;
extern U_2a7700 __cdecl Query(hulk_uintptr, U_2a7700, const void*, const void*, U_2a7700);
extern char CameraRTTI;
extern char EntityRTTI_2a7700;
struct ParticleController_nv_2a7700 {
    void Finish(U_2a7700);
};

void pure3d::ParticleController::vfunc_5(void* __p0) { hulk_uintptr arg = (hulk_uintptr)__p0;

    U_2a7700 x = Query(arg, 0, &EntityRTTI_2a7700, &CameraRTTI, 0);
    ((ParticleController_nv_2a7700*)this)->Finish(x);
}
