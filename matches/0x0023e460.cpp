#include "gen/fight.h"

extern void* operator new(unsigned int);
extern void __fastcall InitTrack(void*);
extern int WaitTrackVtable;
struct WaitTrack_23e460 {
    int* vptr;
    int pad4[2];
    int x, y, z;
};

template <> void* fight::TrackFactoryTemplate<fight::WaitTrack>::vfunc_5() {
    WaitTrack_23e460* p = (WaitTrack_23e460*)operator new(0x18);
    if (p) {
        InitTrack(p);
        p->vptr = (int*)&WaitTrackVtable;
        p->x = 0;
        p->y = 0;
        p->z = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
