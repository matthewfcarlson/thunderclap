// STATUS: equivalent (tools/equiv.py level 3: 19942 inputs, branch coverage 2/2)
// fight::TrackFactoryTemplate<hulkfight::motion::DriftToPositionTrack>::vfunc_5 @ 0x0017e350
#include "compat/ptr.h"
#include "gen/fight.h"

void* __cdecl FUN_0008d690(hulk_uintptr);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
struct DriftToPositionTrack_17e350 {
    virtual void vfunc_0();
    char pad04[4];
    int count;
    int field0c;
    float field10;
    unsigned char field14;
    char pad15[3];
    int field18;
    int field1c;
    int field20;
    unsigned char field24;
    unsigned char field25;
    char pad26[2];
    int field28;
    void FUN_00236d40();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::DriftToPositionTrack>::vfunc_5() {
    DriftToPositionTrack_17e350* track = (DriftToPositionTrack_17e350*)FUN_0008d690(0x2c);
    if (track) {
        track->FUN_00236d40();
        new(track) DriftToPositionTrack_17e350;
        track->field0c = 0;
        track->field14 = 0;
        track->field10 = -1.0f;
        track->field18 = 0;
        track->field1c = 0;
        track->field20 = 0;
        track->field24 = 1;
        track->count = 1;
        track->field25 = 0;
        track->field28 = 0;
    }
    return (void*)(track);
}
