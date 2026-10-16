#include "gen/fight.h"

extern "C" char DAT_003fd094[];
class StopTrack_6f670 {
  public:
    void Init();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::TrackFactoryTemplate<CGrappleEffectStopTrack>::vfunc_5() {
    StopTrack_6f670* p = (StopTrack_6f670*)FUN_0008d690(0x18);
    if (p) {
        p->Init();
        *(int*)p = ((int)DAT_003fd094);
        return (void*)(p);
    }
    return (void*)(0);
}
