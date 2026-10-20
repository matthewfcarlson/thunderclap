#include "compat/ptr.h"
#include "gen/choreo2.h"

void* __cdecl alloc(unsigned int);
extern int vt_22a8a0;
struct RestPoseDriver_nv_22a8a0 {
    void InitA(choreo2::RestPoseDriver*);
    void InitB(choreo2::RestPoseDriver*);
};

void* choreo2::RestPoseDriver::vfunc_5() {
    choreo2::RestPoseDriver* p = (choreo2::RestPoseDriver*)alloc(0x20);
    if (p) {
        ((RestPoseDriver_nv_22a8a0*)(p))->InitA(this);
        *(hulk_intptr*)p = (hulk_intptr)&vt_22a8a0;
        ((RestPoseDriver_nv_22a8a0*)(p))->InitB(this);
        return (void*)(p);
    }
    return (void*)(0);
}
