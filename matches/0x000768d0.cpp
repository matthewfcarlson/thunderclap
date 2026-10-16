#include "gen/fight.h"

extern "C" char DAT_003fe828[];
extern void* __cdecl operator_new(unsigned int);
class CGrappleInvincibleTrack_768d0 {
  public:
    void Init();
};

template <> void* fight::TrackFactoryTemplate<CGrappleInvincibleTrack>::vfunc_5() {
    CGrappleInvincibleTrack_768d0* p = (CGrappleInvincibleTrack_768d0*)operator_new(0x18);
    if (p) {
        p->Init();
        *(int*)p = ((int)DAT_003fe828);
        return (void*)(p);
    }
    goto fail;
fail:
    return (void*)(0);
}
