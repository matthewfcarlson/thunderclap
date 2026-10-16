#include "gen/fight.h"

extern "C" char DAT_004143f0[];
struct HitPushbackAddTrack_15a110 {
    unsigned int vt;
    char pad[4];
    int mTwo;
    int mZero;
    float mOne;
    void Init();
};
extern void* __cdecl Alloc(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HitPushbackAddTrack>::vfunc_5() {
    HitPushbackAddTrack_15a110* p = (HitPushbackAddTrack_15a110*)Alloc(0x14);
    if (p) {
        p->Init();
        p->vt = ((int)DAT_004143f0);
        p->mZero = 0;
        p->mOne = 1.0f;
        p->mTwo = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
