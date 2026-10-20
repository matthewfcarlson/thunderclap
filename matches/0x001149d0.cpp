#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0040dbe4[];
extern "C" void* __cdecl Alloc(unsigned int);
class AIHistoryCountTrack_1149d0 {
  public:
    int vptr;
    char pad[8];
    int member;
    AIHistoryCountTrack_1149d0();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::ai::AIHistoryCountTrack>::vfunc_5() {
    AIHistoryCountTrack_1149d0* p = (AIHistoryCountTrack_1149d0*)Alloc(16);
    if (p) {
        p->AIHistoryCountTrack_1149d0::AIHistoryCountTrack_1149d0();
        p->vptr = ((hulk_intptr)DAT_0040dbe4);
        p->member = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
