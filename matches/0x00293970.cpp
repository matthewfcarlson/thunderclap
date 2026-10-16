#include "gen/pure3d.h"

typedef unsigned int U_293970;
extern U_293970 __cdecl Query(U_293970, U_293970, const void*, const void*, U_293970);
extern char CameraRTTI;
extern char EntityRTTI_293970;
struct CameraAnimationController_nv_293970 {
    void Finish(U_293970);
};

void pure3d::CameraAnimationController::vfunc_5(void* __p0) { U_293970 arg = (U_293970)__p0;

    U_293970 x = Query(arg, 0, &EntityRTTI_293970, &CameraRTTI, 0);
    ((CameraAnimationController_nv_293970*)this)->Finish(x);
}
