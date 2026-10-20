#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0040ebb0[];
typedef unsigned int u32_11b4c0;
void* __cdecl alloc(unsigned int);
struct TrackFactoryTemplate_nv_11b4c0 {
    void initialize();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::ai::MotionBoostTrack>::vfunc_5() {
    fight::TrackFactoryTemplate<hulkfight::ai::MotionBoostTrack>* p = (fight::TrackFactoryTemplate<hulkfight::ai::MotionBoostTrack>*)alloc(0x2c);
    if (p != 0) {
        ((TrackFactoryTemplate_nv_11b4c0*)(p))->initialize();
        *(u32_11b4c0*)((char*)p + 0x0c) = 0;
        *(u32_11b4c0*)((char*)p + 0x14) = 0;
        *(u32_11b4c0*)((char*)p + 0x18) = 0;
        *(u32_11b4c0*)((char*)p + 0x1c) = 0;
        *(u32_11b4c0*)((char*)p + 0x20) = 0;
        *(u32_11b4c0*)((char*)p + 0x28) = 0;
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0040ebb0);
        *(u32_11b4c0*)((char*)p + 0x10) = 0xbf800000;
        *(u32_11b4c0*)((char*)p + 0x24) = 0x3f800000;
        return (void*)(p);
    }
    return (void*)(0);
}
