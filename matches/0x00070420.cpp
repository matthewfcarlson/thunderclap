#include "gen/fight.h"

typedef unsigned int uint;
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Track_70420 {
    void* Init();
};

template <> void* fight::TrackFactoryTemplate<CSmartPropUpdateAttachmentTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x48);
    if (p)
        return (void*)(((Track_70420*)p)->Init());
    return (void*)(0);
}
