#include "gen/fight.h"

extern "C" char DAT_003fbfa4[];
struct CDriftTrack_76410 {
    unsigned int vptr;
    unsigned int pad4;
    int field8;
    unsigned int fieldc;
    float field10;
    unsigned int field14;
    float field18;
    void init();
};
extern "C" void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<CDriftTrack>::vfunc_5() {
    CDriftTrack_76410* p = (CDriftTrack_76410*)operator_new(0x1c);
    if (p) {
        p->init();
        p->vptr = ((int)DAT_003fbfa4);
        p->fieldc = 0;
        p->field10 = -1.0f;
        p->field14 = 0;
        p->field18 = 1.0f;
        p->field8 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
