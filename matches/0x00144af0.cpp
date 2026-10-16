#include "gen/hulkfight.h"

extern "C" char DAT_0041306c[];
typedef unsigned int u32_144af0;
void* __cdecl Alloc(unsigned int);
struct SlowMotionAction_144af0 {
    void init();
    char pad[0x1c];
    void* volatile owner;
};
struct Track_144af0 {
    char pad[0x1c];
};

int hulkfight::motion::SlowMotionTrack::vfunc_10(int a, int b, int c) {
    SlowMotionAction_144af0* p = (SlowMotionAction_144af0*)Alloc(0x28);
    if (p) {
        p->init();
        *(volatile u32_144af0*)p = ((int)DAT_0041306c);
        p->owner = 0;
        p->owner = this;
        return (int)(p);
    }
    return (int)(0);
}
