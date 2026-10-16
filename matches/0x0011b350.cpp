#include "gen/fight.h"

extern "C" char DAT_0040eb50[];
typedef unsigned int u32_11b350;
extern void* __cdecl alloc(unsigned int);
class MotionStopTrack_11b350 {
  public:
    MotionStopTrack_11b350();
    u32_11b350 a;
    u32_11b350 b;
    u32_11b350 c;
    int x;
    float y;
};

template <> void* fight::TrackFactoryTemplate<hulkfight::ai::MotionStopTrack>::vfunc_5() {
    MotionStopTrack_11b350* p = (MotionStopTrack_11b350*)alloc(0x14);
    if (p) {
        p->MotionStopTrack_11b350::MotionStopTrack_11b350();
        p->a = ((int)DAT_0040eb50);
        p->x = 0;
        p->y = -1.0f;
        return (void*)(p);
    }
    return (void*)(0);
}
