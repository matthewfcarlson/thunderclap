// STATUS: equivalent (tools/equiv.py level 3: 19941 inputs, branch coverage 2/2)
// fight::TrackFactoryTemplate<hulkfight::ai::TokenSupressTrack>::vfunc_5 @ 0x00114910
#include "compat/ptr.h"
#include "gen/fight.h"

void* __cdecl FUN_0008d690(hulk_uintptr);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
namespace hulkfight { namespace ai {
struct TokenSupressTrack_114910 {
    virtual void vfunc_0();
    char pad4[4];
    int count;
    int valueC;
    float value10;
    unsigned char active;
    char pad15[3];
    float value18;
    unsigned char flag1c;
    unsigned char flag1d;
    char pad1e[2];
    void FUN_00236d40();
};
}}
namespace fight {
}
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::TokenSupressTrack>::vfunc_5() {
    hulkfight::ai::TokenSupressTrack_114910* track = (hulkfight::ai::TokenSupressTrack_114910*)FUN_0008d690(0x20);
    if (track) {
        track->FUN_00236d40();
        new(track) hulkfight::ai::TokenSupressTrack_114910;
        track->active = 1;
        track->count = 1;
        track->valueC = 0;
        track->value10 = -1.0f;
        track->value18 = -1.0f;
        track->flag1c = 0;
        track->flag1d = 0;
    }
    return (void*)(track);
}
