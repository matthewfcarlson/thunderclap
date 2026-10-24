#include "gen/choreo2.h"

struct ThisCall_002223f0 {
    void InitRestPose(void*);
};
extern void* RestPoseVtable;

choreo2::RestPoseDriver* choreo2::RestPoseDriver::FUN_0022a5d0(void* arg) {
    ((ThisCall_002223f0*)(this))->InitRestPose(arg);
    *(void**)this = &RestPoseVtable;
    return (choreo2::RestPoseDriver*)(this);
}
