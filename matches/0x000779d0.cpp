#include "gen/fight.h"

extern "C" char DAT_003fc184[];
struct Sub_779d0 {
    void subinit();
};
struct CAIHintTrack_779d0 {
    char pad[32];
    void init();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::TrackFactoryTemplate<CAIHintTrack>::vfunc_5() {
    CAIHintTrack_779d0* p = (CAIHintTrack_779d0*)FUN_0008d690(0x20);
    if (p) {
        p->init();
        *(unsigned int*)p = ((int)DAT_003fc184);
        *(unsigned int*)((char*)p + 0xc) = 0;
        *(unsigned int*)((char*)p + 0x10) = 0xbf800000;
        ((Sub_779d0*)((char*)p + 0x18))->subinit();
        *(unsigned int*)((char*)p + 8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
