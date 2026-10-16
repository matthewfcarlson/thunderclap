#include "gen/fight.h"

extern "C" char DAT_003fe6c8[];
typedef unsigned int u32_76590;
void* __cdecl Allocate(unsigned int);
class Track_76590 {
  public:
    void Init();
};

template <> void* fight::TrackFactoryTemplate<CGrappleAutoTargetTrack>::vfunc_5() {
    void* p = Allocate(0x3c);
    if (p) {
        ((Track_76590*)p)->Init();
        *(u32_76590*)p = ((int)DAT_003fe6c8);
        return (void*)(p);
    }
    return (void*)(0);
}
