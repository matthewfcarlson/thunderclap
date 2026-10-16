#include "gen/fight.h"

extern "C" char DAT_003fbc24[];
struct CMoveAddTrack_771a0 {
    unsigned int vf;
    unsigned int x4;
    unsigned int x8;
    unsigned int xc;
    float x10;
    float x14;
    unsigned int x18;
    void Init();
};
extern void* Alloc(unsigned int);

template <> void* fight::TrackFactoryTemplate<CMoveAddTrack>::vfunc_5() {
    CMoveAddTrack_771a0* p = (CMoveAddTrack_771a0*)Alloc(0x1c);
    if (p != 0) {
        p->Init();
        p->x10 = 1.0f;
        p->x14 = 1.0f;
        *(unsigned int*)p = ((int)DAT_003fbc24);
        p->xc = 0;
        p->x18 = 0;
        p->x8 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
