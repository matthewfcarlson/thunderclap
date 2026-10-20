#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00414240[];
void* __cdecl Alloc(hulk_uintptr);
struct HitThrowTrack_159bf0 {
    hulk_intptr vt;
    char p04[8];
    int f0c;
    float f10;
    unsigned char f14;
    char p15[3];
    int f18;
    float f1c;
    int f20;
    int f24;
    int f28;
    void InitTrack();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HitThrowTrack>::vfunc_5() {
    HitThrowTrack_159bf0* p = (HitThrowTrack_159bf0*)Alloc(0x2c);
    if (p) {
        p->InitTrack();
        p->f0c = 0;
        p->f18 = 0;
        p->f24 = 0;
        p->f28 = 0;
        p->vt = ((hulk_intptr)DAT_00414240);
        p->f10 = -1.0f;
        p->f14 = 1;
        p->f1c = 30.0f;
        p->f20 = -5;
        return (void*)(p);
    }
    return (void*)(0);
}
