#include "gen/fight.h"

extern "C" char DAT_003fbc9c[];
struct CSweepTrack_776d0 {
    virtual ~CSweepTrack_776d0();
    char pad[0x20];
};
extern void* __cdecl Allocate(unsigned int);
struct InitClass {
    void Init();
};

template <> void* fight::TrackFactoryTemplate<CSweepTrack>::vfunc_5() {
    CSweepTrack_776d0* p = (CSweepTrack_776d0*)Allocate(0x24);
    if (p) {
        ((InitClass*)p)->Init();
        *(unsigned long*)((char*)p + 0x0c) = 0;
        *(unsigned long*)((char*)p + 0x14) = 0;
        *(unsigned long*)((char*)p + 0x1c) = 0;
        *(unsigned long*)((char*)p + 0x20) = 0;
        *(unsigned long*)p = ((int)DAT_003fbc9c);
        *(unsigned long*)((char*)p + 0x10) = 0x3f800000;
        *(unsigned long*)((char*)p + 0x18) = 0xffffffff;
        *(unsigned long*)((char*)p + 8) = 1;
    } else {
        return (void*)(0);
    }
    return (void*)(p);
}
