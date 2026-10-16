#include "gen/fight.h"

extern "C" char DAT_003fc094[];
extern void* __cdecl alloc(unsigned int);
class CStageTrack_77620 {
  public:
    void Init();
};

template <> void* fight::TrackFactoryTemplate<CStageTrack>::vfunc_5() {
    CStageTrack_77620* p = (CStageTrack_77620*)alloc(0x14);
    if (p) {
        p->Init();
        *(int*)p = ((int)DAT_003fc094);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        *(int*)((char*)p + 8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
