#include "gen/fight.h"

extern "C" char DAT_00413004[];
class Motion_146750 {
  public:
    void Init();
};
extern void* __cdecl Alloc(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::MotionTrailStopTrack>::vfunc_5() {
    Motion_146750* p = (Motion_146750*)Alloc(0x14);
    if (p) {
        p->Init();
        *(int*)p = ((int)DAT_00413004);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        *(int*)((char*)p + 8) = 1;
        return (void*)(p);
    }
    return (void*)((void*)((char*)p - (char*)p));
}
