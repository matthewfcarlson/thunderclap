#include "compat/ptr.h"
extern "C" char DAT_00412fd4[];
struct MotionBlurTrack {
  public:
    void Init();
    hulk_intptr vf;
    int mHdr;
    int mOne;
    int mZero;
    float mA;
    float mB;
    float mC;
    int mD;
    int mE;
};
extern void* operator new(unsigned int);

MotionBlurTrack* CreateTrack() {
    MotionBlurTrack* p = (MotionBlurTrack*)operator new(0x24);
    if (p != 0) {
        p->Init();
        p->vf = ((hulk_intptr)DAT_00412fd4);
        p->mZero = 0;
        p->mA = 0.1f;
        p->mB = 0.9f;
        p->mC = 1.0f;
        p->mD = 0;
        p->mE = 0;
        p->mOne = 1;
        return p;
    }
    return 0;
}
