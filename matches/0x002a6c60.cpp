// Same code shape as 0x00293970 (propagated; names are from that function)
#include "gen/pure3d.h"

typedef unsigned int U_2a6c60;
extern U_2a6c60 __cdecl Query(U_2a6c60, U_2a6c60, const void*, const void*, U_2a6c60);
extern char CameraRTTI;
extern char EntityRTTI_2a6c60;
struct ProceduralVertexAnimController_nv_2a6c60 {
    void Finish(U_2a6c60);
};

void pure3d::ProceduralVertexAnimController::vfunc_5(void* __p0) { U_2a6c60 arg = (U_2a6c60)__p0;

    U_2a6c60 x = Query(arg, 0, &EntityRTTI_2a6c60, &CameraRTTI, 0);
    ((ProceduralVertexAnimController_nv_2a6c60*)this)->Finish(x);
}
