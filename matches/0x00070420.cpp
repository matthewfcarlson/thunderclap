#include "gen/fight.h"

typedef unsigned int uint;
extern void* __cdecl Allocate(unsigned int);
struct Track_70420 {
    void* Init();
};

template <> void* fight::TrackFactoryTemplate<CSmartPropUpdateAttachmentTrack>::vfunc_5() {
    void* p = Allocate(0x48);
    if (p)
        return (void*)(((Track_70420*)p)->Init());
    return (void*)(0);
}
