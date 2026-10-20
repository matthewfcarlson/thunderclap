#include "compat/ptr.h"
#include "gen/global.h"

extern "C" void _ReadWriteBarrier();
struct CCameraManager_9c410 {
    void cameraMethod(float, float, bool);
};
struct CameraArgs {
    float first;
    float second;
    bool third;
};

template <> void Closure3<CCameraManager, void, float, float, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; CameraArgs * args = (CameraArgs *)__p1; hulk_intptr unused2 = (hulk_intptr)__p2;

    float first = args->first;
    _ReadWriteBarrier();
    ((*(CCameraManager_9c410 * *)&this->f_20)->*(*(void (CCameraManager_9c410::**)(float, float, bool))&this->f_1c))(first, args->second, args->third);
    _ReadWriteBarrier();
}
