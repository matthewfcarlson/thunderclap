#include "gen/fight.h"

extern "C" char DAT_00413618[];
extern "C" void* __cdecl FUN_0008d690(int size);

struct CDTrack {
    int f0, f4, f8, fc, f10, f14, f18, f1c, f20, f24;
    void Init();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::CivilianDetachTrack>::vfunc_5() {
    CDTrack* p = (CDTrack*)FUN_0008d690(0x28);
    if (p != 0) {
        p->Init();
        *(volatile int*)&p->fc = 0;
        *(volatile int*)&p->f0 = ((int)DAT_00413618);
        *(volatile int*)&p->f10 = 0;
        *(volatile int*)&p->f14 = 0;
        *(volatile int*)&p->f18 = 0;
        *(volatile int*)&p->f1c = 0;
        *(volatile int*)&p->f20 = 0;
        *(volatile int*)&p->f24 = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
