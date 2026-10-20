#include "gen/fight.h"

extern void* FUN_0008d690(unsigned int);
extern void* PostEvent_StringTrack_vtable;
struct Helper_12df70 {
    void FUN_00236d40();
};
struct SubHelper {
    void FUN_0027af00();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::PostEvent_StringTrack>::vfunc_5() {
    char* p = (char*)FUN_0008d690(0x20);
    if (p) {
        ((Helper_12df70*)p)->FUN_00236d40();
        *(void**)p = &PostEvent_StringTrack_vtable;
        *(unsigned int*)(p + 0xc) = 0;
        ((SubHelper*)(p + 0x10))->FUN_0027af00();
        p[0x18] = 0;
        p[0x19] = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
