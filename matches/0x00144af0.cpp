#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern "C" char DAT_0041306c[];
typedef unsigned int u32_144af0;
void* __cdecl Alloc(hulk_uintptr);
struct SlowMotionAction_144af0 {
    void init();
    char pad[0x1c];
    void* volatile owner;
};
struct Track_144af0 {
    char pad[0x1c];
};

hulk_intptr hulkfight::motion::SlowMotionTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    SlowMotionAction_144af0* p = (SlowMotionAction_144af0*)Alloc(0x28);
    if (p) {
        p->init();
        *(volatile hulk_uintptr*)p = ((hulk_intptr)DAT_0041306c);
        p->owner = 0;
        p->owner = this;
        return (hulk_intptr)(p);
    }
    return (int)(0);
}
