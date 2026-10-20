// Same code shape as 0x00293970 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/pure3d.h"

typedef unsigned int U_2a93e0;
extern U_2a93e0 __cdecl Query(hulk_uintptr, U_2a93e0, const void*, const void*, U_2a93e0);
extern char CameraRTTI;
extern char EntityRTTI_2a93e0;
struct LightAnimationController_nv_2a93e0 {
    void Finish(U_2a93e0);
};

void pure3d::LightAnimationController::vfunc_5(void* __p0) { hulk_uintptr arg = (hulk_uintptr)__p0;

    U_2a93e0 x = Query(arg, 0, &EntityRTTI_2a93e0, &CameraRTTI, 0);
    ((LightAnimationController_nv_2a93e0*)this)->Finish(x);
}
